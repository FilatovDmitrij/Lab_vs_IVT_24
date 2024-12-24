#include <iostream>
using namespace std;

int main()
{
	int n, a = 0, b = 0;
	cin >> n;

	while (n != 0)
	{
		b = b * 10 + n % 10;
		n /= 10;
		a++;
	}
	
	cout  <<  setw(a) << setfill('0') << b;

	return 0;
}