#include <iostream>
using namespace std;
int main()
{
	int n, a = 0;
	cin >>n;
	if (n <= 0)
	{
		cout << "Tupich?";
	}
	else 
	{
		for (int i = 1; i <= n; i++)
		{
			a += i;
		}
		cout <<a;
	}
	return 0;
}