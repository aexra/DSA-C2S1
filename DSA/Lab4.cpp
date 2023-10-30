#include "Lab4.h"

void Lab4::t1()
{
	HRND rnd = new Random();

	LT* a20 = rnd->GetRandFilledArrayT<LT>(20);
	LT* a500 = rnd->GetRandFilledArrayT<LT>(500);
	LT* a1000 = rnd->GetRandFilledArrayT<LT>(1000);
	LT* a3000 = rnd->GetRandFilledArrayT<LT>(3000);
	LT* a5000 = rnd->GetRandFilledArrayT<LT>(5000);
	LT* a10000 = rnd->GetRandFilledArrayT<LT>(10000);

	SortResult ssr20 = SelectionSort(a20, 20);
	SortResult ssr500 = SelectionSort(a500, 500);
	SortResult ssr1000 = SelectionSort(a1000, 1000);
	SortResult ssr3000 = SelectionSort(a3000, 3000);
	SortResult ssr5000 = SelectionSort(a5000, 5000);
	SortResult ssr10000 = SelectionSort(a10000, 10000);

	SortResult isr20 = InclusionSort(a20, 20);
	SortResult isr500 = InclusionSort(a500, 500);
	SortResult isr1000 = InclusionSort(a1000, 1000);
	SortResult isr3000 = InclusionSort(a3000, 3000);
	SortResult isr5000 = InclusionSort(a5000, 5000);
	SortResult isr10000 = InclusionSort(a10000, 10000);

	SortResult bsr20 = BubbleSort(a20, 20);
	SortResult bsr500 = BubbleSort(a500, 500);
	SortResult bsr1000 = BubbleSort(a1000, 1000);
	SortResult bsr3000 = BubbleSort(a3000, 3000);
	SortResult bsr5000 = BubbleSort(a5000, 5000);
	SortResult bsr10000 = BubbleSort(a10000, 10000);

	/*SortResult qsr20 = QuickSort(a20, 0, 20);
	SortResult qsr500 = QuickSort(a500, 0, 500);
	SortResult qsr1000 = QuickSort(a1000, 0, 1000);
	SortResult qsr3000 = QuickSort(a3000, 0, 3000);
	SortResult qsr5000 = QuickSort(a5000, 0, 5000);
	SortResult qsr10000 = QuickSort(a10000, 0, 10000);*/
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
	SortResult result;
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
	return result;
}
SortResult Lab4::SelectionSort(int* num, int size)
{
	SortResult result;
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
	return result;
}
SortResult Lab4::BubbleSort(int* num, int size)
{
	SortResult result;
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
	return result;
}
SortResult Lab4::QuickSort(int* numbers, size_t start, size_t end)
{
	SortResult result;
	if (start >= end)
		return result;
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
	return result;
}
void Lab4::Swap(int* numbers, size_t first, size_t second)
{
	auto temp{ numbers[first] };
	numbers[first] = numbers[second];
	numbers[second] = temp;
}