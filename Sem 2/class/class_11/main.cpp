#include <iostream>
#include <vector>
#include <stack>
#include "set.h"
#include "money.h"
using namespace std;

int main() {
	Set<Money> vec(3);
	vec.Print();
	Money el = vec.max();
	vec.add_max_to_stack(el, 0);
	vec.Print();
	vec.del_min_from_stack();
	vec.Print();
	el = vec.srednee();
	vec.summ_srednee(el);
	vec.Print();
	return 0;
}