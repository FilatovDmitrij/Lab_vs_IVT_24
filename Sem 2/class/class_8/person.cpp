#include "person.h"
#include <iostream>
using namespace std;

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(std::string str, int t) {
    name = str;
    age = t;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

Person::~Person() {
}

Person& Person::operator=(const Person& p) {
    if (this == &p) { return *this; }
    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show() {
    cout << "Person name: " << name << endl;
    cout << "Person age: " << age << endl;
    cout << endl;
}

void Person::Input() {
    cout << "Person name: "; cin >> name;
    cout << "Person age: "; cin >> age;
    cout << endl;
}

void Person::HandleEvent(const TEvent& event) {
    if (event.what == EvMessage) {
        switch (event.command) {
        case cmGet: cout << "Name " << get_name() << endl; break;
        }
    }
}