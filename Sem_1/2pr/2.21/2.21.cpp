#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	bool zero_flag = false, order_flag = true;
	int a, b;

	cin >> a;

	while (!zero_flag)
	{
		cin >> b;
		if (b == 0) { zero_flag = true; }
		else if (b > a) { a = b; }
		else { order_flag = false; }
	}

	if (order_flag) { cout << "Числа в последовательности упорядочены по возрастанию."; }
	else { cout << "Числа в последовательности не упорядочены."; }

	return 0;
}