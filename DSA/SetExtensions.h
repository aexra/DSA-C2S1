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

//template <typename T>
//std::set<T> ConcatSets(const std::set<T>& _Left, const std::set<T>& _Right)
//{
//	std::set<T> newset;
//	for (auto node : _Left)
//		newset.insert(node);
//	for (auto node : _Right)
//		newset.insert(node);
//	return newset;
//}