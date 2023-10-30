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
	void InclusionSort(int* num, int size);
	void SelectionSort(int* num, int size);
	void BubbleSort(int* num, int size);
	void QuickSort(int* numbers, size_t start, size_t end);
	void Swap(int* numbers, size_t first, size_t second);
#pragma endregion
};

