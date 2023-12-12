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
};

template<typename T>
inline void List<T>::push(T value)
{
	if (!this->head) {
		this->head = new IEnumerable<T>::Node(value);
		return;
	}
}

template<typename T>
inline void List<T>::remove(size_t i)
{
}
