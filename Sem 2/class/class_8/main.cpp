#include <iostream>
#include "student.h"
#include "Dialog.h"
#include "list.h"
using namespace std;

int main() {
	auto* pers1 = new Person();
	pers1->Input();
	pers1->Show();
	auto* stud1 = new Student();
	stud1->Input();
	stud1->Show();

	auto* pers2 = new Person();
	pers2->Input();
	auto* stud2 = new Student();
	stud2->Input();
	List l(10);
	Object* p = pers2;
	l.Add();
	p = stud2;
	l.Add();
	l.Show();
	l.Del();
	cout << "size of list is" << l() << endl;

	Dialog d;
	d.EndExec();
	return 0;
}
