#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
    int n, a;
	bool pl = false;
	bool mn = false;
	cin >> n;

	for (int i = 1; i <= n ; i++)
	{
		cin >> a;
		if (!pl && !mn)
		{
			if (a > 0) { pl = true; }
			else if (a < 0) { mn = true; }
		}
	}

	if (pl) { cout << "Первое число было положительным."; }
	else if(mn) { cout << "Первое число было отрицательным."; }
	else { cout << "Последовательность состоит из нулей."; }

	return 0;
}