#include <iostream>
#include "Abiturient.h"

using namespace std;

Abiturient::Abiturient(string fullName, string specialty, int examScore)
{
    this->fullName = fullName;
    this->specialty = specialty;
    this->examScore = examScore;
}

Abiturient::Abiturient(const Abiturient& other)
{
    fullName = other.fullName;
    specialty = other.specialty;
    examScore = other.examScore;
}

void Abiturient::setFullName(string fullName) { this->fullName = fullName; }
string Abiturient::getFullName() { return fullName; }

void Abiturient::setSpecialty(string specialty) { this->specialty = specialty; }
string Abiturient::getSpecialty() { return specialty; }

void Abiturient::setExamScore(int examScore) { this->examScore = examScore; }
int Abiturient::getExamScore() { return examScore; }

void Abiturient::showInfo()
{
    cout << "ФИО: " << fullName << endl;
    cout << "Специальность: " << specialty << endl;
    cout << "Балл ЕГЭ: " << examScore << endl;
}
