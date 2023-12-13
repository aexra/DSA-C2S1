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
#include "UltraCoolNamespace.h"

/*			LAB CLASS				*/
class Lab6 : public Lab
{
#pragma region Private
private:
	// 1 = Array, 2 = Linked
	unsigned short type1 = 2;
	unsigned short type2 = 2;

	void fake1();
	void fake2();

	Queue<int> linkedqueue1;
	Queue<int> linkedqueue2;
	ArrayQueue<int> arrayqueue1;
	ArrayQueue<int> arrayqueue2;
	List<int> linkedlist;
	ArrayList<int> arraylist;

	unsigned short ask1or2(std::string question = "Чё? [1/2]: ", std::string error = "Лее по цифрам попадать научись...");
	unsigned short ask123(std::string question = "Чё? [1/2]: ", std::string error = "Лее по цифрам попадать научись...");

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
