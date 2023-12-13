#include "Lab6.h"
using namespace SpecialFunctionsForLabs;

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

//void Lab6::fake1()
//{
//	Queue<int> q1 = getRandFilledQueue<int>(5);
//	Queue<int> q2 = getRandFilledQueue<int>(5);
//	(q2 += q1).cout();
//}
//
//void Lab6::fake2()
//{
//	List<int> list = getRandFilledList<int>(5, -100, 100);
//	list.cout();
//	list.swap(0, list.find(list.min()));
//	list.cout();
//}

unsigned short Lab6::ask1or2(std::string question, std::string error)
{
	unsigned short key = 0;
	while (true) {
		key = input<unsigned int>(question);
		if (key == 1 || key == 2) break;
		else std::cout << error << std::endl;
	}
	return key;
}

void Lab6::fake1()
{
	size_t key = ask1or2("\nКакой тип данных использовать?\n1. ArrayQueue\n2. LinkedQueue\nЧё? [1/2]: ");
	if (key == 1) {

	}
	else {

	}
}

void Lab6::fake2()
{
	
}

// the InTeRfAcE
void Lab6::t1()
{
	std::cout << "Вас приветствует Мастер диалога шестой лабы." << std::endl;
	while (true) {
		char key = input<char>("Продолжить? [y/n]: ");
		if (key == 'n' || key == 'N') {
			break;
		}
		else {
			size_t key = ask1or2("\nКакую задачу запустить? [1/2]: ", "Это не номер задачи! Давай заново.");
			if (key == 1) {
				fake1();
			}
			else {
				fake2();
			}
		}
	}
	std::cout << "\nСпасибо что были с нами до самого конца. - Мастер диалога шестой лабы." << std::endl;
}

// will not be usable in this lab
void Lab6::t2()
{
}