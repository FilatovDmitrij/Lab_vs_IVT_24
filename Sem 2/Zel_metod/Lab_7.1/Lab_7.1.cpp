#include <iostream>
#include <complex>

using namespace std;

int mul(double a, double b) 
{ 
   return a * b; 
}

complex<double> mul(complex<double> a, complex<double> b)
{ 
   return a * b; 
}

int main()
{
	complex<double> num1(0.5, -1.7);   
	complex<double> num2(4.1, -9.0);

	cout << mul(num1, num2) << endl;

	int num3= 5;
	int num4= 8;

	cout << mul(num3, num4) << endl;

	return 0;
}
