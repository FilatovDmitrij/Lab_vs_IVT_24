#include <iostream>
using namespace std;

int main()
{
	int n, a;
	cout << " N: ";
	cin >> n;
	a = sqrt(n);
	if ((pow(a, 2) == n) && (n != 0) && (n != 1))
	{
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				cout << " * ";
			}

			cout << endl;
		}
	}
	else
	{
		cout << "Niga dyaj?";
	}
	return 0;
}