#pragma once

#include <iostream>

template<typename T>
class ArrayQueue
{
private:
	size_t length = 0;
	T* _Ary = new T[length];
public:
	T add(T value);
	T pop();
	size_t count();
	void cout(std::string end = "\n", std::ostream& os = std::cout);

	ArrayQueue<T> operator += (ArrayQueue<T> _Right);
};

template<typename T>
inline T ArrayQueue<T>::add(T value)
{
	T* newAry = new T[length + 1];
	for (size_t i = 0; i < length; i++) {
		newAry[i] = _Ary[i];
	}
	newAry[length] = value;
	delete _Ary;
	_Ary = newAry;
	length++;
	return value;
}

template<typename T>
inline T ArrayQueue<T>::pop()
{
	T value = _Ary[0];
	T* newAry = new T[length - 1];
	for (size_t j = 1; j < length; j++) {
		newAry[j-1] = _Ary[j];
	}
	delete _Ary;
	_Ary = newAry;
	length--;
	return value;
}

template<typename T>
inline size_t ArrayQueue<T>::count()
{
	return length;
}

template<typename T>
inline void ArrayQueue<T>::cout(std::string end, std::ostream& os)
{
	os << "[";
	for (size_t i = 0; i < length; i++) {
		os << _Ary[i] << (i == length - 1 ? "" : ", ");
	}
	os << "]" << end;
}

template<typename T>
inline ArrayQueue<T> ArrayQueue<T>::operator+=(ArrayQueue<T> _Right)
{
	for (size_t i = 0; i < _Right.count(); i++) {
		this->add(_Right[i]);
	}
	return *this;
}
