#pragma once
#include "iostream"
#include "object.h"
using namespace std;

class Person :public Object {
protected:
    string name;
    int age;
public:
    Person();
    Person(std::string, int);
    Person(const Person&);
    ~Person();
    void Show();
    void Input();
    void set_name(std::string str) { name = str; };
    void set_age(int a) { age = a; };
    int get_age() const { return age; };
    string get_name() { return name; };
    Person& operator=(const Person&);
    void HandleEvent(const TEvent& event);
};