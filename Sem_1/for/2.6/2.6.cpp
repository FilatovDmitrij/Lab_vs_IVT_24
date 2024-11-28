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
	return 0;
}