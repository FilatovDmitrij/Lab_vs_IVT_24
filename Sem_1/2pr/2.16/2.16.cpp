#include <iostream>
using namespace std;

int main()
{
	int n, a= 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1) { a -= i; }
		else { a += i; }
	}
	cout << a;

	return 0;
}