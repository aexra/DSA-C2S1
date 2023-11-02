#include "Lab4.h"

void Lab4::t1()
{
	HRND rnd = new Random();

	LT* ua20 = rnd->GetRandFilledArrayT<LT>(20);
	LT* ua500 = rnd->GetRandFilledArrayT<LT>(500);
	LT* ua1000 = rnd->GetRandFilledArrayT<LT>(1000);
	LT* ua3000 = rnd->GetRandFilledArrayT<LT>(3000);
	LT* ua5000 = rnd->GetRandFilledArrayT<LT>(5000);
	LT* ua10000 = rnd->GetRandFilledArrayT<LT>(10000);

	SortResult ssr20 = SelectionSort(GetArrayClone(ua20, 20), 20);
	SortResult ssr500 = SelectionSort(GetArrayClone(ua500, 500), 500);
	SortResult ssr1000 = SelectionSort(GetArrayClone(ua1000, 1000), 1000);
	SortResult ssr3000 = SelectionSort(GetArrayClone(ua3000, 3000), 3000);
	SortResult ssr5000 = SelectionSort(GetArrayClone(ua5000, 5000), 5000);
	SortResult ssr10000 = SelectionSort(GetArrayClone(ua10000, 10000), 10000);

	DropTable(ssr20, ssr500, ssr1000, ssr3000, ssr5000, ssr10000, "Сортировка сравнениями");

	SortResult isr20 = InclusionSort(GetArrayClone(ua20, 20), 20);
	SortResult isr500 = InclusionSort(GetArrayClone(ua500, 500), 500);
	SortResult isr1000 = InclusionSort(GetArrayClone(ua1000, 1000), 1000);
	SortResult isr3000 = InclusionSort(GetArrayClone(ua3000, 3000), 3000);
	SortResult isr5000 = InclusionSort(GetArrayClone(ua5000, 5000), 5000);
	SortResult isr10000 = InclusionSort(GetArrayClone(ua10000, 10000), 10000);

	DropTable(ssr20, isr500, isr1000, isr3000, isr5000, isr10000, "Сортировка вставками");

	SortResult bsr20 = BubbleSort(GetArrayClone(ua20, 20), 20);
	SortResult bsr500 = BubbleSort(GetArrayClone(ua500, 500), 500);
	SortResult bsr1000 = BubbleSort(GetArrayClone(ua1000, 1000), 1000);
	SortResult bsr3000 = BubbleSort(GetArrayClone(ua3000, 3000), 3000);
	SortResult bsr5000 = BubbleSort(GetArrayClone(ua5000, 5000), 5000);
	SortResult bsr10000 = BubbleSort(GetArrayClone(ua10000, 10000), 10000);

	DropTable(bsr20, bsr500, bsr1000, bsr3000, bsr5000, bsr10000, "Сортировка пузырьком");

	/*SortResult qsr20 = QuickSort(a20, 0, 20);
	SortResult qsr500 = QuickSort(a500, 0, 500);
	SortResult qsr1000 = QuickSort(a1000, 0, 1000);
	SortResult qsr3000 = QuickSort(a3000, 0, 3000);
	SortResult qsr5000 = QuickSort(a5000, 0, 5000);
	SortResult qsr10000 = QuickSort(a10000, 0, 10000);*/

	//DropTable(qsr20, qsr500, qsr1000, qsr3000, qsr5000, qsr10000, "Сортировка быстрая");
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
	double startms = clock();
	for (int i = 1; i < size; i++)
	{
		int value = num[i];
		int index = i;
		while ((index > 0) && (num[index - 1] > value) && result.comparisons++)
		{
			num[index] = num[index - 1];
			result.exchanges++;
			index--;
			result.iterations++;
		}
		num[index] = value;
	}
	result.ms = clock() - startms;
	return result;
}
SortResult Lab4::SelectionSort(int* num, int size)
{
	SortResult result;
	double startms = clock();
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min] && result.comparisons++)
				min = j;
			result.iterations++;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
		result.exchanges++;
	}
	result.ms = clock() - startms;
	return result;
}
SortResult Lab4::BubbleSort(int* num, int size)
{
	SortResult result;
	double startms = clock();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j] && result.comparisons++)
			{
				int temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
				result.exchanges++;
			}
			result.iterations++;
		}
	}
	result.ms = clock() - startms;
	return result;
}
SortResult Lab4::QuickSort(int* numbers, size_t start, size_t end)
{
	SortResult result;
	double startms = clock();
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
	result.ms = clock() - startms;
	return result;
}
void Lab4::Swap(int* numbers, size_t first, size_t second)
{
	auto temp{ numbers[first] };
	numbers[first] = numbers[second];
	numbers[second] = temp;
}
size_t CTFI(int i)
{
	string s = to_string(i);
	return s.length() > 8 ? 0 : s.length() > 6? 1 : 2;
}
string GTFI(int i)
{
	string s = "";
	for (int j = 0; j < CTFI(i); j++)
	{
		s += "\t";
	}
	return s;
}
void Lab4::DropTable(SortResult a20, SortResult a500, SortResult a1000, SortResult a3000, SortResult a5000, SortResult a10000, string msg)
{
	if (msg != "") cout << msg << endl;
	cout << "Размер\t\t\|20\t\t|500\t\t|1000\t\t|3000\t\t|5000\t\t|10000\t\t" << endl;
	cout << "Время\t\t|" << a20.ms << GTFI(a20.ms) << "|" << a500.ms << GTFI(a500.ms) << "|" << a1000.ms << GTFI(a1000.ms) << "|" << a3000.ms << GTFI(a3000.ms) << "|" << a5000.ms << GTFI(a5000.ms) << "|" << a10000.ms << endl;
	cout << "Итерации\t|" << a20.iterations << GTFI(a20.iterations) << "|" << a500.iterations << GTFI(a500.iterations) << "|" << a1000.iterations << GTFI(a1000.iterations) << "|" << a3000.iterations << GTFI(a3000.iterations) << "|" << a5000.iterations << GTFI(a5000.iterations) << "|" << a10000.iterations << endl;
	cout << "Сравнения\t|" << a20.comparisons << GTFI(a20.comparisons) << "|" << a500.comparisons << GTFI(a500.comparisons) << "|" << a1000.comparisons << GTFI(a1000.comparisons) << "|" << a3000.comparisons << GTFI(a3000.comparisons) << "|" << a5000.comparisons << GTFI(a5000.comparisons) << "|" << a10000.comparisons << endl;
	cout << "Обмены\t\t|" << a20.exchanges << GTFI(a20.exchanges) << "|" << a500.exchanges << GTFI(a500.exchanges) << "|" << a1000.exchanges << GTFI(a1000.exchanges) << "|" << a3000.exchanges << GTFI(a3000.exchanges) << "|" << a5000.exchanges << GTFI(a5000.exchanges) << "|" << a10000.exchanges << endl;
	cout << "\n\n";
}
Lab4::LT* Lab4::GetArrayClone(LT* a, size_t size)
{
	LT* newa = new LT[size];
	for (size_t i = 0; i < size; i++)
	{
		newa[i] = a[i];
	}
	return newa;
}
