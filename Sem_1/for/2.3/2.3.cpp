#include <iostream>
using namespace std;

int main()
{
	int n, a = 0;
    cin >> n;

	if (n <= 0)
	{
        cout << "Tupich?";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int b = 1;
			for (int j = i; j <= i * 2; j++)
			{
                b *= j;
			}
            a += b;
		}

        cout << a;
	}

	return 0;
}