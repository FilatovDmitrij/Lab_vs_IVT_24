#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, "ru");

  const int rows = 5;
  const int cols = 5;

  char** mas = new char* [rows];
  for (int i = 0; i < rows; i++) { mas[i] = new char[cols]; }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> mas[i][j];
    }
  }

  cout << "Начальная матрица:" << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << mas[i][j];
    }
    cout << endl;
  }

  char** new_mas = new char* [rows-1];
  for (int i = 0; i < 4; i++) { new_mas[i] = new char[cols]; }

  int k;
  cout << "Введите номер строки, которую нужно удалить: ";
  cin >> k;
  k--;

  int new_i = 0;

  for (int i = 0; i < rows; i++)
  {
    if (i == k) continue;
    for (int j = 0; j < cols; j++)
    {
      new_mas[new_i][j] = mas[i][j];
    }
    new_i++;
  }

  cout << "Конечная матрица:" << endl;

  for (int i = 0; i < rows - 1; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << new_mas[i][j];
    }
    cout << endl;
  }

  for (int i = 0; i < rows; i++) { delete[] mas[i]; }
  delete[] mas;

  for (int i = 0; i < rows - 1; i++) { delete[] new_mas[i]; }
  delete[] new_mas;

  return 0;
}