#include <iostream>
using namespace std;

int main()
{
	int a, n, min, max, *pa = &a;

	cin >> n >> *pa;

	min = *pa;
	max = *pa;

	for (int i = 2; i <= n; i++)
	{
		cin >> *pa;
		if (*pa > max) { max = *pa; }
		else if (*pa < min) { min = *pa; }
	}

	cout << "max = " << max << '\n' << "min = " << min;

	return 0;
}