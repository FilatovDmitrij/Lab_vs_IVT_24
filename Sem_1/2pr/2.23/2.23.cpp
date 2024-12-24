#include <iostream>
using namespace std;

int main()
{
	float n, a, max;
	int i = 2, count = 1;

	cin >> n;

	max = sin(n + 1 / n);

	while (i <= n)
	{
		a = sin(n + i / n);
		if (a > max)
		{
			max = a;
			count = 1;
		}
		else if (a == max) { count++; }
		i++;
	}

	cout << max << endl;
	cout <<  count << endl;

	return 0;
}