#pragma once

#include <set>
#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& os, std::set<T> _Right)
{
	os << "{ ";
	for (T node : _Right)
		os << node << ", ";
	os << "}";
	return os;
}
