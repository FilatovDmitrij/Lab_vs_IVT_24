#include <iostream>
using namespace std;

int main()
{
	unsigned int a = 1, n,  *pa = &a;

	cin >> n;

	for (unsigned int i = 2; i <= n; i++)
	{
		*pa *= i;
	}

	cout << *pa;

	return 0;
}
