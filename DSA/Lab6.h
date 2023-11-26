#pragma once

// BUILT-IN INCLUSIONS
#include <iostream>

// CORE INCLUSION
#include "AexraCore.h"

// CUSTOM INCLUSIONS
#include "Lab.h"
#include "debug.h"
#include "random.h"

// USES
using namespace std;


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

	Node* __GetNode__(size_t i)
	{
		size_t j = 0;
		Node* tmp = this->head;

		while (j != i)
		{
			if (!tmp)
			{
				error("Элемент с таким индексом не найден!\n\n");
				exit(-1);
				//throw out_of_range("kekw");
				//return 0;
			}
			tmp = tmp->next;
			j++;
		}

		return tmp;
	}
public:
	List();

	void cout() override;
	size_t count() override;
	string toString() override;

	void push(T value);
	void remove(size_t i);
	void swap(size_t x, size_t y);
	void reverse();
	size_t find(T value);

	T max();
	T min();
	T sum();
	T mean();

	T operator [] (size_t i);
};

/*			LAB CLASS				*/
class Lab6 : public Lab
{
#pragma region Private
private:
	List<int> getRandList(size_t size = 10, int begin = -10, int end = 10);
#pragma endregion
#pragma region Public
public:
	[[noreturn]] void t1() override;
	[[noreturn]] void t2() override;
#pragma endregion
};