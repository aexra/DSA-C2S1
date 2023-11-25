#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"

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


// QUEUE CLASS
template <class T>
class Queue
{

};

// LIST CLASS
template <class T>
class List
{
private:
	struct Node
	{
		Node* next = nullptr;
		T value = T{};
	};

	Node* head = nullptr;
public:
	List();
	
	void push(T value);
	void remove(size_t i);
	size_t count();

	T operator [] (size_t i);
};