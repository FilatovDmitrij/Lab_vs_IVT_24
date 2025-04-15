#include <iostream>
#include "fraction.h"

using namespace std;

fraction::fraction(int first, double second)
{
    if (first >= 0 && second >= 0 && second < 1) { this->first = first; this->second = second; }
    else cout << "Некорректные данные!" << endl;
}

void fraction::Read()
{
    int first; 
    double second;
    
    cout << "Введите first: ";
    cin >> first;

    cout << "Введите second: ";
    cin >> second;

    if (first >= 0 && second >= 0 && second < 1) { this->first = first; this->second = second; }
    else cout << "Некорректные данные";
}

void fraction::Show()
{
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

void fraction::multiply(double k)
{
    double result = (first + second) * k;
    first = static_cast<int>(result);
    second = result - first;

    if (second >= 1.0) {
        first += static_cast<int>(second);
        second -= static_cast<int>(second);
    }
    else if (second < 0) {
	    first -= 1;
        second += 1.0;
    }
}
