#include "list.h"
#include "Student.h"

List::List(int s) {
    size = s;
    data = new Object * [s];
}

List::~List() {
    if (data != nullptr) delete[] data;
    data = nullptr;
}

void List::Add(void)
{
	Object* tmp;
	cout << "if you want to put Person press 1" << endl;
	cout << "---------------or--------------" << endl;
	cout << "if you want to put Student press 2" << endl;
	int c;
	cin >> c;
	if (c == 1)
	{
		Person* p = new Person;
		p->Input();
		tmp = p;
		if (cur < size)
		{
			data[cur] = tmp;
			cur++;
		}
	}
	else if (c == 2)
	{
		Student* s = new Student;
		s->Input();
		tmp = s;
		if (cur < size)
		{
			data[cur] = tmp;
			cur++;
		}
	}
}

void List::Show() {
    if (cur == 0) { std::cout << "empty" << std::endl; }
    Object** p = data;
    for (int i = 0; i < cur; i++) {
        (*p)->Show();
        p++;
    }
}

void List::Del() {
    if (cur) cur--;
}

int List::operator()()
{
	return cur;
}

void List::HandleEvent(const TEvent& event) {
    if (event.what == EvMessage) {
        Object** p = data;
        for (int i = 0; i < cur; i++) {
            (*p)->Show();
            p++;
        }
    }
}