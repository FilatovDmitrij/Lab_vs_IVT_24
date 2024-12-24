#include <iostream>
using namespace std;

int main()
{
    float a, b, c, x1, x2, sq;
	cin >> a >> b >> c;
	sq = sqrt(b * b - 4 * a * c);
	if (sq > 0)
	{
		x1 = -(b + sq) / (2 * a);
		x2 = -(b - sq) / (2 * a);

		cout << x1 << endl << x2;
	}
	    else if (sq == 0) 
	    { 
		x1 = -b / 2 * a; 
		cout << x1;
	    }
	    else
		{
		cout << "???";
	}

	return 0;
}