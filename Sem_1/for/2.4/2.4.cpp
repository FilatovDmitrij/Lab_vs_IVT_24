#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if ((n % 2 == 0) || (n <= 3))
	{
		cout << "Tupich?";
	}
	else
	{
		int a = n / 2;
		int b = 1;
		int c = (n / 2) + 1;

		for (int i = 1; i <= c; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				cout << ' ';
			}

			a--;

			for (int j = 1; j <= b; j++)
			{
				cout << '*';
			}

			b += 2;

			cout << endl;
		}
	}
	return 0;
}