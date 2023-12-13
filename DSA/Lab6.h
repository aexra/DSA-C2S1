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
#include "ArrayList.h"
#include "Queue.h"
#include "ArrayQueue.h"

/*			LAB CLASS				*/
class Lab6 : public Lab
{
#pragma region Private
private:
	template<typename T>
	List<T> getRandFilledList(size_t count, T min = -10, T max = 10);
	template<typename T>
	Queue<T> getRandFilledQueue(size_t count, T min = -10, T max = 10);
#pragma endregion
#pragma region Public
public:
	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;
#pragma endregion
};
