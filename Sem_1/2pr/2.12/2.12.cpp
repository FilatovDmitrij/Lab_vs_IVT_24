#include <iostream>
using namespace std;
int main()
{
	int n, tmp, min, max;
	cin >> n >> tmp;
	min = tmp;
	max = tmp;

	for (int i = 2; i <= n; i++)
	{
		cin >> tmp;
		if (tmp > max) { max = tmp; }
		else if (tmp < min) { min = tmp; }
	}

	cout <<  max + min;

	return 0;
}