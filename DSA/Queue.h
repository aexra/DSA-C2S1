#pragma once
#include "IEnumerable.h"

template<typename T>
class Queue : public IEnumerable<T>
{
private:
public:
	void add(T value);
	T pop();
};

template<typename T>
inline void Queue<T>::add(T value)
{
	if (!this->head) {
		this->head = new IEnumerable<T>::Node(value);
		this->length++;
		return;
	}

	auto tmp = this->head;
	while (tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = new IEnumerable<T>::Node(value);
	tmp->next->prev = tmp;

	this->length++;
}

template<typename T>
inline T Queue<T>::pop()
{
	try {
		T value = this->head->value;
		auto next = this->head->next;
		delete this->head;
		this->head = next;
		this->head->prev = nullptr;
		this->head->next->prev = this->head;
		this->length--;
		return value;
	}
	catch () {
		return nullptr;
	}
}

