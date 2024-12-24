#include <iostream>
using namespace std;

int main()
{
	int n;
	float x, a = 1, sum;

	cin >> n >> x;

	sum = 1 + x;

	for (int i = 2; i <= n; i++)
	{
		a *= i;
		sum += (pow(x, i) / a);
	}

	cout << sum << endl;

	return 0;
}