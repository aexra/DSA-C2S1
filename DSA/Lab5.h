#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "debug.h"
#include "random.h"
#include "Lab4.h"

// USES
using namespace std;

// ��������� ���������� ������������ ������
struct SearchResult
{
	unsigned int ms = 0;
	unsigned int comparisons = 0;

	size_t size;
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

	SearchResult LinSearch(int arr[], int requiredKey, int arrSize);
	void DropTable(SearchResult results[], size_t size, string msg = "");
#pragma endregion
};

