#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "debug.h"
#include "random.h"

// USES
using namespace std;

// структура результата выполненной сортировки
struct SortResult
{
	unsigned int ms = 0;
	unsigned int iterations = 0;
	unsigned int comparisons = 0;
	unsigned int exchanges = 0;
};

/*			LAB CLASS				*/
class Lab4 : public Lab
{
#pragma region Private
private:

#pragma endregion
#pragma region Public
public:
	typedef int LT;

	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;

	void PrintAry(LT* _Right, size_t size);

	// соритровки
	SortResult InclusionSort(int* num, int size);
	SortResult SelectionSort(int* num, int size);
	SortResult BubbleSort(int* num, int size);
	SortResult QuickSort(int* numbers, size_t start, size_t end);
	void __QuickSort__(int a[], int start, int end, SortResult& result);
	int __Partition__(int a[], int start, int end, SortResult& result);
	void DropTable(SortResult a25, SortResult a50, SortResult a75, string msg = "");
	void DropTable(SortResult a20, SortResult a500, SortResult a1000, SortResult a3000, SortResult a5000, SortResult a10000, string msg = "");
	
	LT* GetArrayClone(LT* a, size_t size);
#pragma endregion
};

