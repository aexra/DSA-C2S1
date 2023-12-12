#include "Lab6.h"

template<typename T>
List<T> Lab6::getRandFilledList(size_t count, T min, T max)
{
	List<T> list;
	HRND rnd = Random::GetInstance();
	if (is_same<T, int>::value) {
		for (size_t i = 0; i < count; i++) {
			list.push(rnd->randi(min, max));
		}
	} else if (is_same<T, float>::value || is_same<T, double>::value) {
		for (size_t i = 0; i < count; i++) {
			list.push(rnd->randf(min, max));
		}
	}
	return list;
}

void Lab6::t1()
{
	
}

void Lab6::t2()
{
	List<int> list = getRandFilledList<int>(10);
	list.cout();
}
