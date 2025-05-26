#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Student : public Person
{
protected:
	float rating;
public:
	Student();
	Student(const Student&);
	Student(string, int, float);
	~Student() {};
	void Show();
	void Input();
	void setRating(float r) { rating = r; }
	float getRating() { return rating; }
	Student& operator=(const Student&);
};