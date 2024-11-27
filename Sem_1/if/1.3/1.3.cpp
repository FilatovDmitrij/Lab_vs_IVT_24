#include <iostream>
using namespace std;

int main() 
{
	double a;

	cin >>a;

	if (a < 5)
	{
		cout << a * 3;
	}
	else
	{
		if (a <= 7)
		{
			cout << a / 10;
		}
		else
		{
			cout << a + 3;
		}
	}

	return 0;
}