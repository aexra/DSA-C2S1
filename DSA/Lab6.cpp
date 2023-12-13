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

void Lab6::fake1()
{
	/*Queue<int> q1 = getRandFilledQueue<int>(5);
	Queue<int> q2 = getRandFilledQueue<int>(5);
	(q2 += q1).cout();*/

	if (type1 == 1) {

	}
	else {

	}
}

void Lab6::fake2()
{
	/*List<int> list = getRandFilledList<int>(5, -100, 100);
	list.cout();
	list.swap(0, list.find(list.min()));
	list.cout();*/

	if (type2 == 1) {
		
	}
	else {

	}
}

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

// the InTeRfAcE
void Lab6::t1()
{
	// configure default values
	linkedlist = getRandFilledList<int>(10);
	linkedqueue2 = getRandFilledQueue<int>(10);
	for (size_t i = 0; i < linkedlist.count(); i++) {
		arraylist.push(linkedlist[i]);
		linkedqueue1.add(linkedlist[i]);
		arrayqueue1.add(linkedlist[i]);
	}
	for (size_t i = 0; i < linkedqueue2.count(); i++) {
		arrayqueue2.add(linkedqueue2[i]);
	}
	// end configuring

	std::cout << "Вас приветствует Мастер диалога шестой лабы." << std::endl;
	while (true) {
		unsigned short key = 0;
		while (!(1 <= key && key <= 4)) {
			key = input<unsigned int>(
				"\t\tМЕНЮ\n1. Сменить тип данных\n2. К значениям\n3. Выполнить задачу\n4. Выйти\nВыберите [1-4]: "
			);
		}
		switch (key) {
		case 1:
			unsigned short key = ask1or2("Формат какого типа данных вы хотите изменить?\n1. Очередей\n2. Списков");
			unsigned short type = ask1or2("Выберите тип\n1. Массив\n2. Связная структура");
			if (key == 1) type1 = type;
			else type2 = type;
			std::cout << "Формат " << (key == 1? "очередей" : "списков") << " изменен на " << (type == 1 ? "массив" : "связную структуру");
			break;
		case 2:

			break;
		case 3:
			unsigned short key = ask1or2("Какую задачу? [1/2]: ");
			if (key == 1) {
				fake1();
			}
			else {
				fake2();
			}
			break;
		case 4:
			return;
		}
	}
	std::cout << "\nСпасибо что были с нами до самого конца. - Мастер диалога шестой лабы." << std::endl;
}

// will not be usable in this lab
void Lab6::t2()
{
}