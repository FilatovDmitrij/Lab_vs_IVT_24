#include "fraction.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    double k; 
    cout << "Введите k: ";
    cin >> k;

    fraction f;
    f.Read();
    cout << "Исходное число:" << endl;
    f.Show();

    f.multiply(k);
    cout << "Результат умножения:" << endl;
    f.Show();

    return 0;
}