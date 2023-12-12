#include "Lab6.h"

void Lab6::t1()
{
	auto list = List<int>();
	list.push(5);
	list.push(4);
	list.remove(1);
	list.push(3);
	list.push(6);
	list.push(28);
	list.remove(0);
	list.cout();
	cout << "\n" << list.count();
}

void Lab6::t2()
{
	auto ie = IEnumerable<int>();
	ie.cout();
}
