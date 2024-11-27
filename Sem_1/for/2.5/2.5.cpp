#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n > 2)
	{
		int spaces = n - 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= spaces; j++)
			{
				cout << "  ";
			}
			spaces--;
			for (int j = 1; j <= i; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "N - íàòóðàëüíîå ÷èñëî áîëüøå 2.";
	}

	return 0;
}