#pragma once
#include <iostream>
#include <string>

template<typename T>
class IEnumerable {
public:
	virtual void cout(std::ostream& os = std::cout);
	virtual size_t count();
	virtual std::string toString();

	template<typename U>
	friend std::ostream& operator << (std::ostream& os, IEnumerable<U>& _Right);
	T operator [] (size_t i);

	IEnumerable() {};
protected:
	struct Node {
		Node* next = nullptr;
		Node* prev = nullptr;
		T value;

		Node(T value) : value(value) {}
	};

	Node* head = nullptr;
	Node* next = nullptr;
	size_t length = 0;

	T get(size_t i);
	Node* getNode(size_t i);
};

template<typename T>
inline void IEnumerable<T>::cout(std::ostream& os)
{
	os << this->toString();
}

template<typename T>
inline size_t IEnumerable<T>::count()
{
	return this->length;
}

template<typename T>
inline std::string IEnumerable<T>::toString()
{
	Node* tmp = this->head;
	std::string str = "[";
	while (tmp) {
		str += std::to_string(tmp->value);
		tmp = tmp->next;
		if (tmp) str += ", ";
		else break;
	}
	str += "]";
	return str;
}

template<typename T>
inline T IEnumerable<T>::operator[](size_t i)
{
	return this->get(i);
}

template<typename T>
inline T IEnumerable<T>::get(size_t i)
{
	Node* tmp = this->head;
	size_t k = 0;
	while (tmp) {
		if (k == i) {
			return tmp->value;
		}
		k++;
		tmp = tmp->next;
	}
	throw std::exception("Out of range!");
}

template<typename T>
inline IEnumerable<T>::Node* IEnumerable<T>::getNode(size_t i)
{
	Node* tmp = this->head;
	size_t k = 0;
	while (tmp) {
		if (k == i) {
			return tmp;
		}
		k++;
		tmp = tmp->next;
	}
	throw std::exception("Out of range!");
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, IEnumerable<U>& _Right)
{
	_Right.cout(os);
	return os;
}
