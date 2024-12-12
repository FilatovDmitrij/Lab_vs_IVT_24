#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << " N: ";
	cin >> n;

	if (n <= 2)
	{
		cout << "Lol";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << "* ";
		}
		cout << endl;

		for (int i = 1; i <= (n - 2); i++)
		{
			cout << "* ";
			for (int i = 1; i <= (n - 2); i++)
			{
				cout << "  ";
			}
			cout << "* " << endl;
		}

		for (int i = 1; i <= n; i++)
		{
			cout << "* ";
		}
	}

	return 0;
}