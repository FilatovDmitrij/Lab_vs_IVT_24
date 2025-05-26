#pragma once
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Graph {
private:
    struct Connection {
        int destination;
        int cost;
    };

    std::vector<int> points;
    std::vector<std::vector<Connection>> links;
    bool directional;

    int locatePoint(int point) const {
        auto position = std::find(points.begin(), points.end(), point);
        return (position != points.end()) ? std::distance(points.begin(), position) : -1;
    }

public:
    explicit Graph(bool directed = false) : directional(directed) {}

    void includePoint(int point) {
        if (locatePoint(point) == -1) {
            points.push_back(point);
            links.resize(points.size());
        }
    }

    void excludePoint(int point) {
        int position = locatePoint(point);
        if (position != -1) {
            for (auto& connections : links) {
                connections.erase(std::remove_if(connections.begin(), connections.end(),
                    [point](const Connection& c) { return c.destination == point; }), connections.end());
            }
            points.erase(points.begin() + position);
            links.erase(links.begin() + position);
        }
    }

    void establishLink(int origin, int target, int cost) {
        int originPos = locatePoint(origin);
        int targetPos = locatePoint(target);
        
        if (originPos != -1 && targetPos != -1) {
            links[originPos].push_back({target, cost});
            if (!directional) {
                links[targetPos].push_back({origin, cost});
            }
        }
    }

    void breakLink(int origin, int target) {
        int originPos = locatePoint(origin);
        int targetPos = locatePoint(target);
        
        if (originPos != -1 && targetPos != -1) {
            links[originPos].erase(
                std::remove_if(links[originPos].begin(), links[originPos].end(),
                    [target](const Connection& c) { return c.destination == target; }),
                links[originPos].end());
            
            if (!directional) {
                links[targetPos].erase(
                    std::remove_if(links[targetPos].begin(), links[targetPos].end(),
                        [origin](const Connection& c) { return c.destination == origin; }),
                    links[targetPos].end());
            }
        }
    }

    std::vector<int> exploreBreadth(int startPoint) {
        std::vector<int> path;
        std::vector<bool> visited(points.size(), false);
        std::queue<int> exploration;

        int startPos = locatePoint(startPoint);
        if (startPos == -1) return path;

        exploration.push(startPos);
        visited[startPos] = true;

        while (!exploration.empty()) {
            int current = exploration.front();
            exploration.pop();
            path.push_back(points[current]);

            for (const Connection& connection : links[current]) {
                int neighborPos = locatePoint(connection.destination);
                if (!visited[neighborPos]) {
                    visited[neighborPos] = true;
                    exploration.push(neighborPos);
                }
            }
        }

        return path;
    }

    std::vector<int> exploreDepth(int startPoint) {
        std::vector<int> path;
        std::vector<bool> visited(points.size(), false);
        std::stack<int> exploration;

        int startPos = locatePoint(startPoint);
        if (startPos == -1) return path;

        exploration.push(startPos);

        while (!exploration.empty()) {
            int current = exploration.top();
            exploration.pop();

            if (!visited[current]) {
                visited[current] = true;
                path.push_back(points[current]);

                for (const Connection& connection : links[current]) {
                    int neighborPos = locatePoint(connection.destination);
                    if (!visited[neighborPos]) {
                        exploration.push(neighborPos);
                    }
                }
            }
        }

        return path;
    }

    std::map<int, int> calculatePaths(int startPoint) {
        const int MAX = std::numeric_limits<int>::max();
        std::map<int, int> distances;
        std::priority_queue<std::pair<int, int>, 
                          std::vector<std::pair<int, int>>,
                          std::greater<std::pair<int, int>>> queue;

        for (int point : points) {
            distances[point] = MAX;
        }

        int startPos = locatePoint(startPoint);
        if (startPos == -1) return distances;

        distances[startPoint] = 0;
        queue.push({0, startPoint});

        while (!queue.empty()) {
            int currentDist = queue.top().first;
            int currentPoint = queue.top().second;
            queue.pop();

            if (currentDist > distances[currentPoint]) continue;

            int currentPos = locatePoint(currentPoint);
            for (const Connection& connection : links[currentPos]) {
                int newDist = currentDist + connection.cost;
                if (newDist < distances[connection.destination]) {
                    distances[connection.destination] = newDist;
                    queue.push({newDist, connection.destination});
                }
            }
        }

        return distances;
    }

    void display(sf::RenderWindow& window) {
        const float circleSize = 200.f;
        const sf::Vector2f middle(400.f, 300.f);
        std::map<int, sf::Vector2f> pointLocations;

        float angle = 0.f;
        const float angleChange = 2 * 3.14159f / points.size();

        for (size_t i = 0; i < points.size(); ++i) {
            pointLocations[points[i]] = {
                middle.x + circleSize * std::cos(angle),
                middle.y + circleSize * std::sin(angle)
            };
            angle += angleChange;
        }

        sf::Font textStyle;
        if (textStyle.loadFromFile("arial.ttf")) {
            for (size_t i = 0; i < points.size(); ++i) {
                for (const Connection& connection : links[i]) {
                    sf::Vertex line[] = {
                        sf::Vertex(pointLocations[points[i]], sf::Color::Black),
                        sf::Vertex(pointLocations[connection.destination], sf::Color::Black)
                    };
                    window.draw(line, 2, sf::Lines);

                    sf::Text costDisplay;
                    costDisplay.setFont(textStyle);
                    costDisplay.setString(std::to_string(connection.cost));
                    costDisplay.setCharacterSize(12);
                    costDisplay.setFillColor(sf::Color::Red);
                    costDisplay.setPosition(
                        (pointLocations[points[i]].x + pointLocations[connection.destination].x) / 2,
                        (pointLocations[points[i]].y + pointLocations[connection.destination].y) / 2
                    );
                    window.draw(costDisplay);
                }
            }

            for (const auto& location : pointLocations) {
                sf::CircleShape pointShape(20.f);
                pointShape.setPosition(location.second.x - 20, location.second.y - 20);
                pointShape.setFillColor(sf::Color::Blue);
                window.draw(pointShape);

                sf::Text pointLabel;
                pointLabel.setFont(textStyle);
                pointLabel.setString(std::to_string(location.first));
                pointLabel.setCharacterSize(14);
                pointLabel.setFillColor(sf::Color::White);
                pointLabel.setPosition(location.second.x - 5, location.second.y - 8);
                window.draw(pointLabel);
            }
        }
    }
};