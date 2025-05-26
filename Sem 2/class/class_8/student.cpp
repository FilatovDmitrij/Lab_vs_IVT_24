#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() :Person() {
    rating = 0;
}

Student::Student(std::string str, int t, float r) : Person(str, t) {
    rating = r;
}

Student::Student(const Student& stud) {
    name = stud.name;
    age = stud.age;
    rating = stud.rating;
}

Student& Student::operator=(const Student& stud) {
    if (&stud == this) { return *this; }
    name = stud.name;
    age = stud.age;
    rating = stud.rating;
    return *this;
}

void Student::Show() {
    cout << "Student name: " << name << endl;
    cout << "Student age: " << age << endl;
    cout << "Student rating: " << rating << endl;
    cout << endl;
}

void Student::Input() {
    cout << "Student name: "; cin >> name;
    cout << "Student age: "; cin >> age;
    cout << "Student rating: "; cin >> rating;
    cout << endl;
}