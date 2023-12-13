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
	linkedqueue1 = getRandFilledQueue<int>(10);
	linkedqueue2 = getRandFilledQueue<int>(10);
	for (size_t i = 0; i < linkedlist.count(); i++) {
		arraylist.push(linkedlist[i]);
	}
	for (size_t i = 0; i < linkedqueue1.count(); i++) {
		arrayqueue1.add(linkedqueue2[i]);
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
		{
			unsigned short tkey = ask1or2("\nФормат какого типа данных вы хотите изменить?\n1. Очередей\n2. Списков\nВыберите [1/2]: ");
			unsigned short type = ask1or2("Выберите тип\n1. Массив\n2. Связная структура\nВыберите [1/2]: ");
			if (tkey == 1) type1 = type;
			else type2 = type;
			std::cout << "Формат " << (tkey == 1 ? "очередей" : "списков") << " изменен на " << (type == 1 ? "массив" : "связную структуру");
			break;
		}
		case 2:
		{
			bool toExit = false;
			while (!toExit) {
				unsigned short akey = 0;
				while (!(1 <= akey && akey <= 3)) {
					akey = input<unsigned int>(
						"\n1. Просмотреть значения\n2. Изменить значения\n3. Назад\nВыберите [1-3]: "
					);
				}
				switch (akey) {
				case 1:
				{
					std::cout << std::endl;
					std::cout << "Очередь1:\t" << linkedqueue1;
					std::cout << "Очередь2:\t" << linkedqueue2;
					std::cout << "Список:\t\t" << linkedlist;
					break;
				}
				case 2:
				{
					if (ask1or2("\nЧто изменяем?\n1. Очередь\n2. Список\nВыберите [1/2]: ") == 1) {
						// очереди
						if (ask1or2("\nКакую очередь?\n1. Первую\n2. Вторую\nВыберите [1/2]: ") == 1) {
							// первая очередь
							if (ask1or2("\nЧто делаем?\n1. Добавить\n2. Удалить\nВыберите [1/2]: ") == 1) {
								// добавить
								size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
								int value = input<unsigned int>("Введите значение: ");
							}
							else {
								// удалить
								size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
							}
						}
						else {
							// вторая очередь
							if (ask1or2("\nЧто делаем?\n1. Добавить\n2. Удалить\nВыберите [1/2]: ") == 1) {
								// добавить
								size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
								int value = input<unsigned int>("Введите значение: ");
							}
							else {
								// удалить
								size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
							}
						}
					}
					else {
						// список
						if (ask1or2("\nЧто делаем?\n1. Добавить\n2. Удалить\nВыберите [1/2]: ") == 1) {
							// добавить
							size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
							int value = input<unsigned int>("Введите значение: ");
							linkedlist.insert(index, value);
						}
						else {
							// удалить
							size_t index = input<unsigned int>("Введите индекс: ", "Такого индекса нет, давай по новой: ", 1);
							linkedlist.remove(index);
						}
					}
					break;
				}
				case 3:
				{
					toExit = true;
					break;
				}
				}
			}
			break;
		}
		case 3:
		{
			unsigned short key = ask1or2("Какую задачу? [1/2]: ");
			if (key == 1) {
				fake1();
			}
			else {
				fake2();
			}
			break;
		}
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