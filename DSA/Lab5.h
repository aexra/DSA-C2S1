#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>
#include <chrono>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "debug.h"
#include "random.h"
#include "Lab4.h"

// USES
using namespace std;

// структура результата выполненного поиска
struct SearchResult
{
	unsigned int ms = 0;
	unsigned int comparisons = 0;

	unsigned int sorted = -1;
	unsigned int size;
	int value;
};

/*			LAB CLASS				*/
class Lab5 : public Lab4
{
#pragma region Private
private:

#pragma endregion
#pragma region Public
public:
	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;

	SearchResult LinearSearch(int arr[], int requiredKey, int arrSize);
	SearchResult BinarySearch(int arr[], int left, int right, int key);
	SearchResult BarrierSearch(int* arr, int value, size_t size);
	uint64_t micros();
	void DropTable(SearchResult results[], size_t size, string msg = "");
#pragma endregion
};

