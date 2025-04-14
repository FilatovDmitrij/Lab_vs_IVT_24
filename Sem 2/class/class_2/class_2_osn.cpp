#include <iostream>
#include "Abiturient.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    Abiturient abiturient1("Иванов Иван Иванович", "Информатика", 85);
    Abiturient abiturient2(abiturient1);

    abiturient2.setFullName("Петров Петр Петрович");
    abiturient2.setExamScore(92);

    cout << "Абитуриент 1:" << endl;
    abiturient1.showInfo();

    cout << "\nАбитуриент 2:" << endl;
    abiturient2.showInfo();

    return 0;
}
