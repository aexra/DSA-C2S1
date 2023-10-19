#pragma once

// BUILT-IN INCLUSIONS

#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "UltraCoolNamespace.h"


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

	template <typename T>
	T* NewPointer() { return new T(); }

	template <typename T>
	T* WritePointer(T* p, T value) { *p = value; return p; }

	template <typename T>
	T ReadPointer(T* p) { return *p; }
#pragma endregion
};

