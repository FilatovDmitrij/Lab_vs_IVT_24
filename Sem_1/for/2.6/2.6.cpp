#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << " N: ";
	cin >> n;

	if (n > 2)
	{
		int a = 0;
		int b = n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				cout << "  ";
			}
			for (int j = 1; j<=b; j++)
			{
				cout << "* ";
			}
			a++;
			b--;
			cout << endl;
		}
	}
	else
	{
		cout << "N - íàòóðàëüíîå ÷èñëî áîëüøå 2.";
	}

	return 0;
}