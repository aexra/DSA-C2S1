#pragma once

#include <time.h>
#include <random>
#include <iostream>

class Random
{
public:
	Random();

	double randf();
	double randf(double begin, double end);
	int randi(int begin = 0, int end = RAND_MAX);

	template <typename T>
	T* GetRandFilledArrayT(size_t size);
	template <typename T>
	T* GetRandFilledArrayT(size_t size, T start);
	template <typename T>
	T* GetRandFilledArrayT(size_t size, T start, T end);
};

typedef Random* HRND;

template<typename T>
inline T* Random::GetRandFilledArrayT(size_t size)
{
	T* arr = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		if (std::is_same<T, int>::value)
		{
			arr[i] = this->randi();
		}
		else
		{
			arr[i] = this->randf();
		}
	}
	return arr;
}
template<typename T>
inline T* Random::GetRandFilledArrayT(size_t size, T start)
{
	T* arr = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		if (std::is_same<T, int>::value)
		{
			arr[i] = this->randi(start);
		}
		else
		{
			arr[i] = this->randf(start);
		}
	}
	return arr;
}
template<typename T>
inline T* Random::GetRandFilledArrayT(size_t size, T start, T end)
{
	T* arr = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		if (std::is_same<T, int>::value)
		{
			arr[i] = this->randi(start, end);
		}
		else
		{
			arr[i] = this->randf(start, end);
		}
	}
	return arr;
}
