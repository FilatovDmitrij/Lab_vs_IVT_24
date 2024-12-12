#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << " N: ";
	cin >> n;
	if (n <= 1)
	{
		cout << "ehehe";
	}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << "* ";
			}

			cout << endl;
		}
	}
	

	return 0;
}