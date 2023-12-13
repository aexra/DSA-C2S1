#pragma once

#include <iostream>

template<typename T>
class ArrayList
{
private:
	size_t length = 0;
	T* _Ary = new T[length];
public:
	T push(T value);
	T remove(size_t i);
	size_t count();
	void cout(std::string end="\n", std::ostream & os = std::cout);
};

template<typename T>
inline T ArrayList<T>::push(T value)
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
inline T ArrayList<T>::remove(size_t i)
{
	T value = _Ary[i];
	T* newAry = new T[length - 1];
	size_t tempk = 0;
	for (size_t j = 0; j < length; j++) {
		if (j != i) {
			newAry[tempk] = _Ary[j];
		}
		tempk++;
	}
	delete _Ary;
	_Ary = newAry;
	length--;
	return value;
}

template<typename T>
inline size_t ArrayList<T>::count()
{
	return length;
}

template<typename T>
inline void ArrayList<T>::cout(std::string end, std::ostream& os)
{
	os << "[";
	for (size_t i = 0; i < length; i++) {
		os << _Ary[i] << (i == length-1? "" : ", ");
	}
	os << "]" << end;
}
