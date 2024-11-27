#include <iostream>
using namespace std;

int main()
{
	int a, b, c, * pa = &a, * pb = &b;

	cin >> *pa >> *pb;
	
	tmp = *pa;
	*pa = *pb;
	*pb = c;

	return 0;
}