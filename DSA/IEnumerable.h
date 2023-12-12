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

	IEnumerable() {};
protected:
	struct Node {
		Node* next = nullptr;
		Node* prev = nullptr;
		T value;
	};
	Node* head = nullptr;
	Node* next = nullptr;
};

template<typename T>
inline void IEnumerable<T>::cout(std::ostream& os)
{
	os << this->toString();
}

template<typename T>
inline size_t IEnumerable<T>::count()
{
	Node* tmp = this->head;
	size_t k = 0;
	while (tmp) {
		k++;
		tmp = tmp->next;
	}
	return k;
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

template<typename U>
inline std::ostream& operator<<(std::ostream& os, IEnumerable<U>& _Right)
{
	_Right.cout(os);
	return os;
}
