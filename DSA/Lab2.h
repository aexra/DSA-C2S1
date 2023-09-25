#pragma once

// BUILT-IN INCLUSIONS

#include <iostream>
#include <fstream>
#include <vector>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "Triangle.h"
#include "debug.h"
#include "random.h"


// USES
using namespace std;

/*			LAB CLASS				*/
class Lab2 : public Lab
{
#pragma region Private
private:

#pragma endregion
#pragma region Public
public:
	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;

	vector<Triangle> parseTrianglesFile(ifstream& ifs);
#pragma endregion
};

