#include "set.h"

set::set()
{
	size = 0;
	data = nullptr;
}
set::set(int a, int b)
{
	size = a;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = b;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}
set::set(const set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
}
set::~set()
{
	delete[] data;
	data = 0;
}
set& set::operator=(const set& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != nullptr) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
	return* this;
}
void set::Add(int el) {
	for (int i = 0; i < size; i++) {
		if (data[i] == el) {
			return;
		}
	}
	int* newData = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	newData[size] = el;
	delete[] data;
	data = newData;
	size++;
}
set& set::operator*(const set& tmp) {
	set result;
	for (int i = 0; i < size; i++) {
		result.Add(data[i]);
	}
	for (int i = 0; i < tmp.size; i++) {
		bool in_result = false;
		for (int j = 0; j < result.size; j++) {
			if (tmp.data[i] == result.data[j]) {
				in_result = true;
				break;
			}
		}
		if (!in_result) {
			result.Add(tmp.data[i]);
		}
	}
	return result;
}
int& set::operator[] (int ind)
{
	if (ind < size) return data[ind];
	else std::cout << "Out of bounds!\n";
}
set set::operator+(const int k)
{
	set tmp(size, k);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] += data[i];
	}
	return tmp;
}
int set::operator() ()
{
	return size;
}
std::ostream& operator<<(std::ostream& out, const  set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.data[i] << " ";
	}
	out << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
}
