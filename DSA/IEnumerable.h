#pragma once
#include <iostream>
#include <string>

template<typename T>
class IEnumerable {
public:
	virtual void cout(std::ostream& os = std::cout);
	virtual size_t count();
	virtual size_t find(T value);
	virtual std::string toString();
	virtual T min();
	virtual T max();
	virtual T sum();
	virtual double mean();

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
inline T IEnumerable<T>::min()
{
	Node* tmp = this->head;
	T min = this->get(0);
	while (tmp) {
		if (tmp->value < min) min = tmp->value;
		tmp = tmp->next;
	}
	return min;
}

template<typename T>
inline T IEnumerable<T>::max()
{
	Node* tmp = this->head;
	T max = this->get(0);
	while (tmp) {
		if (tmp->value > max) max = tmp->value;
		tmp = tmp->next;
	}
	return max;
}

template<typename T>
inline T IEnumerable<T>::sum()
{
	Node* tmp = this->head;
	T sum = 0;
	while (tmp) {
		sum += tmp->value;
		tmp = tmp->next;
	}
	return sum;
}

template<typename T>
inline double IEnumerable<T>::mean()
{
	return this->sum() / (double)this->length;
}

template<typename T>
inline size_t IEnumerable<T>::find(T value)
{
	Node* tmp = this->head;
	size_t k = 0;
	while (tmp) {
		if (tmp->value == value) return k;
		tmp = tmp->next;
		k++;
	}
	return -1;
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
