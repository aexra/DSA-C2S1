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

	cout << "����������� ������������ ��������� ������ �� ������� �������" << endl;

	SearchResult r20 = LinSearch(GetArrayClone(a20, 20), a20[10], 20);
	SearchResult r500 = LinSearch(GetArrayClone(a500, 500), a500[250], 500);
	SearchResult r1000 = LinSearch(GetArrayClone(a1000, 1000), a1000[500], 1000);
	SearchResult r3000 = LinSearch(GetArrayClone(a3000, 3000), a3000[1500], 3000);
	SearchResult r5000 = LinSearch(GetArrayClone(a5000, 5000), a5000[2500], 5000);
	SearchResult r10000 = LinSearch(GetArrayClone(a10000, 10000), a10000[5000], 10000);

	DropTable(new SearchResult[]{r20, r500, r1000, r3000, r5000, r10000}, 6);
}

void Lab5::t2()
{

}

SearchResult Lab5::LinSearch(int arr[], int requiredKey, int arrSize)
{
	SearchResult result;
	result.size = arrSize;
	result.ms = clock();
	for (int i = 0; i < arrSize; i++)
	{
		result.comparisons++;
		if (arr[i] == requiredKey)
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

void Lab5::DropTable(SearchResult results[], size_t size, string msg)
{
	if (msg != "") cout << "\t\t" << msg << endl;
	cout << "������"; for (size_t i = 0; i < size; i++) { cout << "\t\t|" << results[i].size; } cout << endl;
	cout << "�����"; for (size_t i = 0; i < size; i++) { cout << "\t\t|" << results[i].ms; } cout << endl;
	cout << "���������"; for (size_t i = 0; i < size; i++) { cout << (i != 0? "\t" : "") << "\t|" << results[i].comparisons; } cout << endl;
	cout << "\n";
}
