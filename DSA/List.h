#pragma once

#include <string>
#include "IEnumerable.h"

template<typename T>
class List : public IEnumerable<T>
{
private:
public:
	void push(T value);
	void remove(size_t i);
	void insert(size_t i, T value);
};

template<typename T>
inline void List<T>::push(T value)
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
inline void List<T>::remove(size_t i)
{
	if (i == 0) {
		auto next = this->head->next;
		delete this->head;
		this->head = next;
		this->head->prev = nullptr;
		this->head->next->prev = this->head;
		this->length--;
		return;
	}

	auto e1 = this->getNode(i - 1);
	auto e2 = this->getNode(i);
	auto e3 = i + 1 < this->length ? this->getNode(i + 1) : nullptr;

	delete e2;
	e1->next = e3;
	if (e3) e3->prev = e1;

	this->length--;
}

template<typename T>
inline void List<T>::insert(size_t i, T value)
{
	if (i < 0 || i > length) {
		throw std::exception("Out of range!");
	}

	if (i == 0) {
		auto tmp = this->head;
		this->head = new IEnumerable<T>::Node(value);
		this->head->next = tmp;
		if (tmp) tmp->prev = this->head;
		this->length++;
		return;
	}

	auto tmp = this->head;
	size_t k = 0;
	while (k != i) {
		tmp = tmp->next;
		k++;
	}

	auto prev = tmp->prev;
	auto obj = new IEnumerable<T>::Node(value);
	obj->next = tmp;
	obj->prev = prev;
	prev->next = obj;
	tmp->prev = obj;

	this->length++;
}
