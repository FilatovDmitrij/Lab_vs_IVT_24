#include "set.h"
#include <iostream>

int main()
{
	set a(5, 0);
	std::cout << a;
	std::cin >> a;
	std::cout << a;
	a[2] = 100;
	std::cout << a;
	set b(10, 0);
	std::cout << b;
	set c(10, 0);
	c = b + 100;
	std::cout << c;
	std::cout << "length of a= " << a() << std::endl;;
	std::cout << *(a.first()) << " " << *(a.last()) << std::endl;
	iterator i = a.first();
	i++;
	std::cout << *i << std::endl;
	for (i = a.first(); i!=a.last(); i++)
	{
		std::cout << *i << std::endl;
	}
}