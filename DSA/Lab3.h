#pragma once

// BUILT-IN INCLUSIONS

#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"


// USES
using namespace std;

/*			LAB CLASS				*/
class Lab3 : public Lab
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

