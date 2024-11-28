#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n <= 2)
	{
		cout << "Tupich?";
	}
	else
	{
		int a = n - 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				cout << "  ";
			}
			a--;
			for (int j = 1; j <= i; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}