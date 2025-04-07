#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    cout << "Начальная строка ";
    getline(cin, str);
    
    int tmp;

    for (size_t i = 0; i < str.length() - 1; ++i)
    {
        for (size_t j = 0; j < str.length() - i - 1; ++j)
        {
            if ((str[j] > str[j + 1]))
            {
                tmp = str[j]; 
                str[j] = str[j + 1]; 
                str[j + 1] = tmp;
            }
        }
    }

    cout << "Конечная строка ";
    cout << str << endl;

    return 0;
}