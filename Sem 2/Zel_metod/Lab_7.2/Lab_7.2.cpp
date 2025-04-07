#include <iostream>
#include <cstdarg>
#include <limits>

using namespace std;

int min(int args_c, ...)
{
	va_list args;
	va_start(args, args_c);

	int min = numeric_limits<int>::max();
	int curr;

	for (int i = 0; i < args_c; i++)
	{
		curr = va_arg(args, int);
		if (curr < min) { min = curr; }
	}

	va_end(args);

	return min;
}

int main()
{
	cout << "min = " << min(5, 1, 2, 7, 4, 9) << endl;
	cout << "min = " << min(10, 123, 1235, 63, -12, 84, 34, 233, -74, 34, 9876) << endl;
	cout << "min = " << min(12, 123, 1235, 999999, 63, -198, 84, 892137686, 34, 233, 74, 34, 9876) << endl;

	return 0;
}