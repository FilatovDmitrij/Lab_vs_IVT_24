#include <iostream>
using namespace std;

int main()
{
    int n, n1, sum = 0;
	cin >> n;
	n1 = n;

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}

	cout << sum;

	return 0;
}