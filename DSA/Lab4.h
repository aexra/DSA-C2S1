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
	unsigned int ms;
	unsigned int iterations;
	unsigned int comparisons;
	unsigned int exchanges;
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
	void Swap(int* numbers, size_t first, size_t second);
#pragma endregion
};

