#include <iostream>
using namespace std;

int main()
{
    int a;
    float b, c;

    cin >>a >>b >>c; 

    switch (b)
    {
    case 1: cout << b + c; break;
    case 2: cout << b - c; break;
    case 3: cout << b * c; break;
    case 4: 
    {
        if (c == 0)
        {
            cout << "Tupich?";
        }
        else
        {
            cout << b / c;
        }
    }
    default: cout << "....";
    }

    return 0;
}