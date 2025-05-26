#pragma once
#include <iostream>
class iterator
{
	friend class set;
public:
	iterator() { elem = 0; }
	iterator(const iterator& a) { elem = a.elem; }
	bool operator==(const iterator a) { return elem == a.elem; }
	bool operator!=(const iterator a) { return elem != a.elem; }
	void operator++(int a) { elem++; }
	void operator--() { elem--; }
	int operator*()const { return *elem; }
private:
	int* elem;
};
class set
{
public:
	int size;
	int* data;
	iterator beg;
	iterator end;
public:
	set();
	set(int, int);
	set(const set& a);
	~set();
	set& operator=(const set& a);
	set& operator*(const set& a);
	void Add(int a);
	int len() { return size; }
	int& operator[](int);
	set operator +(const int);
	int operator()();
	friend std::ostream& operator<<(std::ostream& out, const set& a);
	friend std::istream& operator>>(std::istream& in, set& a);
	iterator first() { return beg; }
	iterator last() { return end; }
};

