#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"
#include "debug.h"

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


// IEnumerable interface
__interface IEnumerable
{
	virtual void cout() = 0;
	virtual size_t count() = 0;
	virtual string toString() = 0;
};


// QUEUE CLASS
template <class T>
class Queue
{

};

// LIST CLASS
template <class T>
class List : public IEnumerable
{
private:
	struct Node
	{
		Node* next = nullptr;
		T value = T{};

		Node(T value) { this->value = value; }
	};

	Node* head = nullptr;
public:
	List();
	
	void cout() override;
	size_t count() override;
	string toString() override;

	void push(T value);
	void remove(size_t i);
	size_t find(T value);

	T max();
	T min();
	T sum();
	T mean();

	T operator [] (size_t i);
};