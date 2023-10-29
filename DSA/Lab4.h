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
#pragma endregion
};

