#include "Lab5.h"

void Lab5::t1()
{
	HRND rnd = new Random();

	int* a20 = rnd->GetRandFilledArrayT<int>(20);
	int* a500 = rnd->GetRandFilledArrayT<int>(500);
	int* a1000 = rnd->GetRandFilledArrayT<int>(1000);
	int* a3000 = rnd->GetRandFilledArrayT<int>(3000);
	int* a5000 = rnd->GetRandFilledArrayT<int>(5000);
	int* a10000 = rnd->GetRandFilledArrayT<int>(10000);

	cout << "Зависимость длительности линейного поиска от размера массива" << endl;

	SearchResult r20 = LinearSearch(a20, a20[10], 20);
	SearchResult r500 = LinearSearch(a500, a500[250], 500);
	SearchResult r1000 = LinearSearch(a1000, a1000[500], 1000);
	SearchResult r3000 = LinearSearch(a3000, a3000[1500], 3000);
	SearchResult r5000 = LinearSearch(a5000, a5000[2500], 5000);
	SearchResult r10000 = LinearSearch(a10000, a10000[5000], 10000);

	DropTable(new SearchResult[]{ r20, r500, r1000, r3000, r5000, r10000 }, 6);

	cout << "Зависимость длительности ЛИНЕЙНОГО поиска от упорядоченности массива" << endl;

	QuickSort(a10000, 0, 2499);
	SearchResult r25 = LinearSearch(a10000, a10000[8000], 10000);

	QuickSort(a10000, 0, 4999);
	SearchResult r50 = LinearSearch(a10000, a10000[8000], 10000);

	QuickSort(a10000, 0, 7499);
	SearchResult r75 = LinearSearch(a10000, a10000[8000], 10000);

	DropTable(new SearchResult[]{ r25, r50, r75 }, 3);

	cout << "Зависимость длительности БИНАРНОГО поиска от упорядоченности массива" << endl;

	r25 = BinarySearch(a10000, 0, 10000, a10000[8000]); r25.sorted = 25;
	r50 = BinarySearch(a10000, 0, 10000, a10000[8000]); r50.sorted = 50;
	r75 = BinarySearch(a10000, 0, 10000, a10000[8000]); r75.sorted = 75;

	DropTable(new SearchResult[]{ r25, r50, r75 }, 3);
}

void Lab5::t2()
{

}

SearchResult Lab5::LinearSearch(int arr[], int requiredKey, int arrSize)
{
	SearchResult result;
	result.size = arrSize;
	result.ms = clock();
	for (int i = 0; i < arrSize; i++)
	{
		if (result.comparisons++ && arr[i] == requiredKey)
		{
			result.ms = result.ms - clock();
			result.value = i;
			return result;
		}
	}
	result.ms = result.ms - clock();
	result.value = -1;
	return result;
}
SearchResult Lab5::BinarySearch(int arr[], int left, int right, int key)
{
	SearchResult result;
	result.size = right - left + 1;
	result.ms = clock();
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (result.comparisons++ && key < arr[midd])
			right = midd - 1;
		else if (result.comparisons++ && key > arr[midd])
			left = midd + 1;
		else
		{
			result.ms = clock() - result.ms;
			result.value = midd;
			return result;
		}

		if (result.comparisons++ && left > right)
		{
			result.ms = clock() - result.ms;
			result.value = -1;
			return result;
		}
	}
}

void Lab5::DropTable(SearchResult results[], size_t size, string msg)
{
	if (msg != "") cout << "\t\t" << msg << endl;
	cout << "Размер"; for (size_t i = 0; i < size; i++) { cout << "\t\t|" << results[i].size; } cout << endl;
	if (results[0].sorted != -1) { cout << "Сортед"; for (size_t i = 0; i < size; i++) { cout << "\t\t|" << results[i].sorted << "%"; } cout << endl; }
	cout << "Время"; for (size_t i = 0; i < size; i++) { cout << "\t\t|" << results[i].ms; } cout << endl;
	cout << "Сравнения"; for (size_t i = 0; i < size; i++) { cout << (i != 0? "\t" : "") << "\t|" << results[i].comparisons; } cout << endl;
	cout << "\n";
}
