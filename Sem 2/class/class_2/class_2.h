#pragma once
#include <string>

class Abiturient
{
private:
    std::string fullName;    
    std::string specialty;   
    int examScore;           
public:
    Abiturient() : fullName(""), specialty(""), examScore(0) {};
    Abiturient(std::string fullName, std::string specialty, int examScore);
    Abiturient(const Abiturient& other);
    ~Abiturient() {};
    void setFullName(std::string fullName);
    std::string getFullName();
    void setSpecialty(std::string specialty);
    std::string getSpecialty();
    void setExamScore(int examScore);
    int getExamScore();
    void showInfo();
};