#include "Lab4.h"

void Lab4::t1()
{
	HRND rnd = new Random();

	LT* a20 = rnd->GetRandFilledArrayT<LT>(20, 1, 20);
	LT* a500 = rnd->GetRandFilledArrayT<LT>(500);
	LT* a1000 = rnd->GetRandFilledArrayT<LT>(1000);
	LT* a3000 = rnd->GetRandFilledArrayT<LT>(3000);
	LT* a5000 = rnd->GetRandFilledArrayT<LT>(5000);
	LT* a10000 = rnd->GetRandFilledArrayT<LT>(10000);

	QuickSort(a20, 0, 19);
	PrintAry(a20, 20);
}

void Lab4::t2()
{
}

void Lab4::PrintAry(LT* _Right, size_t size)
{
	cout << "[ ";
	for (size_t i = 0; i < size; i++)
	{
		cout << _Right[i] << (i == size - 1 ? " " : ", ");
	}
	cout << "]";
}

SortResult Lab4::InclusionSort(int* num, int size)
{
	for (int i = 1; i < size; i++)
	{
		int value = num[i];
		int index = i;
		while ((index > 0) && (num[index - 1] > value))
		{
			num[index] = num[index - 1];
			index--;
		}
		num[index] = value;
	}
}
SortResult Lab4::SelectionSort(int* num, int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}
SortResult Lab4::BubbleSort(int* num, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j])
			{
				int temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}
SortResult Lab4::QuickSort(int* numbers, size_t start, size_t end)
{
	if (start >= end)
		return;
	size_t current{ start };
	for (size_t i{ start + 1 }; i <= end; i++)
	{
		if (numbers[i] < numbers[start])
		{
			Swap(numbers, ++current, i);
		}
	}
	Swap(numbers, start, current);
	if (current > start)
	{
		QuickSort(numbers, start, current - 1);
	}
	if (end > current + 1)
	{
		QuickSort(numbers, current + 1, end);
	}
}
void Lab4::Swap(int* numbers, size_t first, size_t second)
{
	auto temp{ numbers[first] };
	numbers[first] = numbers[second];
	numbers[second] = temp;
}