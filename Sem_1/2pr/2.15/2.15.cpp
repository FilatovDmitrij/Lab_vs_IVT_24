#include <iostream>
using namespace std;

int main()
{
	int n, n1, s, k;
	bool flag = false;

	cin >> n >> s;

	n1 = n;

	if (s >= 0 && s < 10)
	{
		while (n != 0 && !flag)
		{
			k = n % 10;
			if (k == s)
			{
				cout << s <<  n1;
				flag = true;
			}
			else
			{
				n /= 10;
			}
		}

		if (!flag)
		{
			cout  << s <<  n1;
		}
	}
	else
	{
		cout << s;
	}

	return 0;
}