#include "Lab3.h"
using namespace SpecialFunctionsForLabs;

void Lab3::t1()
{
	// Это тип вводимых и обрабатываемых значений
	typedef int T;

	// Переменные
	T arr[10]{};
	T sum = 0;
	int count = 0;

	// Ввод значений в массив (а зачем?)
	for (unsigned int i = 0; i < 10; i++)
	{
		*(arr + i) = input<T>("Введите значение (какого типа мне не сказали): ");
	}

	// Ведь можно было даже не делать массив а вычислять на ходу
	for (unsigned int i = 0; i < 10; i++)
	{
		if (*(arr + i) % 2 == 0)
		{
			count++;
			sum += *(arr + i);
		}
	}

	cout << endl;
	cout << "Сумма элементов, кратных 2: " << sum << endl;
	cout << "Количество элементов, кратных 2: " << count << endl;
}

void Lab3::t2()
{
	const double C = input<double>("Введите C: ", "Ошибка ввода! Повторите ввод: ", true);
	const unsigned int n = input<unsigned int>("Введите размер одномерного массива: ");

	double* arr = new double[n];
	unsigned int count = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		*(arr + i) = input<double>("Введите " + to_string(i+1) + "-й элемент массива: ", "Ошибка ввода! Повторите ввод: ", true);
		count += *(arr + i) > C;
	}

	cout << endl << "Количество элементов, больших С: " << count;
}
