#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>

// CORE INCLUSION
#include "AexraCore.h"

// CUSTOM INCLUSIONS
#include "Lab.h"
#include "debug.h"
#include "random.h"
#include "List.h"

// USES
using namespace std;

/*			LAB CLASS				*/
class Lab6 : public Lab
{
#pragma region Private
private:

#pragma endregion
#pragma region Public
public:
	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;
#pragma endregion
};
