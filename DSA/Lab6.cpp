#include "Lab6.h"

template<typename T>
List<T> Lab6::getRandFilledList(size_t count, T min, T max)
{
	List<T> list;
	HRND rnd = Random::GetInstance();
	if (std::is_same<T, int>::value) {
		for (size_t i = 0; i < count; i++) {
			list.push(rnd->randi(min, max));
		}
	} else if (std::is_same<T, float>::value || std::is_same<T, double>::value) {
		for (size_t i = 0; i < count; i++) {
			list.push(rnd->randf(min, max));
		}
	}
	return list;
}

template<typename T>
Queue<T> Lab6::getRandFilledQueue(size_t count, T min, T max)
{
	Queue<T> q;
	HRND rnd = Random::GetInstance();
	if (std::is_same<T, int>::value) {
		for (size_t i = 0; i < count; i++) {
			q.add(rnd->randi(min, max));
		}
	}
	else if (std::is_same<T, float>::value || std::is_same<T, double>::value) {
		for (size_t i = 0; i < count; i++) {
			q.add(rnd->randf(min, max));
		}
	}
	return q;
}

void Lab6::t1()
{
	ArrayList<int> lst;
	lst.push(5);
	lst.push(10);
	lst.remove(0);
	lst.cout();

	Queue<int> q1 = getRandFilledQueue<int>(5);
	Queue<int> q2 = getRandFilledQueue<int>(5);
	(q2 += q1).cout();
}

void Lab6::t2()
{
	List<int> list = getRandFilledList<int>(5, -100, 100);
	list.cout();
	list.swap(0, list.find(list.min()));
	list.cout();
}
