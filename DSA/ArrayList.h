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
	T insert(size_t i, T value);
	T remove(size_t i);
	T min();
	size_t find(T value);
	void swap(size_t x, size_t y);
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
inline T ArrayList<T>::insert(size_t i, T value)
{
	T* newAry = new T[length + 1];
	size_t k = 0;
	for (size_t j = 0; j < length + 1; j++) {
		if (i == j) {
			newAry[j] = value;
		}
		else {
			newAry[j] = _Ary[k];
			k++;
		}
	}
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
			tempk++;
		}
	}
	delete _Ary;
	_Ary = newAry;
	length--;
	return value;
}

template<typename T>
inline T ArrayList<T>::min()
{
	T tmp = _Ary[0];
	for (size_t i = 0; i < count(); i++) {
		if (_Ary[i] < tmp) {
			tmp = _Ary[i];
		}
	}
	return tmp;
}

template<typename T>
inline size_t ArrayList<T>::find(T value)
{
	for (size_t i = 0; i < count(); i++) {
		if (_Ary[i] == value) return i;
	}
	return -1;
}

template<typename T>
inline void ArrayList<T>::swap(size_t x, size_t y)
{
	if (y > x) {
		size_t tmp = x;
		x = y;
		y = tmp;
	}

	if (x < 0 || y > count() || x == y) return;
	
	T tmp = _Ary[x];
	_Ary[x] = _Ary[y];
	_Ary[y] = tmp;
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
