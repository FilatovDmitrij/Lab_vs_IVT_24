#include <iostream>
#include "Money.h"
#include "Set.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Set<int> A(2, 0);
	cout << "A = " << A << endl;
	cin >> A;
	cout << "A = " << A << endl;
	Set<int> B(3, 1);
	std::cout << "B = " << B << endl;
	B = A;
	cout << "B = " << B << endl;
	cout << A[1] << endl;
	cout << "the length of A = " << A() << endl;
	cout << "A + B = " << A + B << endl;
	Money a;
	cin >> a;
	cout << a << endl;
	Money b;
	cin >> b;
	cout << b << endl;
	Money sum;
	sum = a + b;
	cout << sum << endl;
	Set<Money> C(2, a);
	cout << "C = " << C << endl;
	cin >> C;
	cout << "C = " << C << endl;
	Set<Money> D(3, a);
	cout << "D = " << D << endl;
	D = C;
	cout << "D = " << D << endl;
	cout << C[1] << endl;
	cout << "the length of C = " << C() << endl;
	cout << "C + D = " << C + D << endl;
	return 0;
}