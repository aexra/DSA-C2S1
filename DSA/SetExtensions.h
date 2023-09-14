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

template <typename T>
std::set<T> operator + (const std::set<T>& _Left, const std::set<T>& _Right)
{
	std::set<T> newset;
	for (auto node : _Left)
		newset.insert(node);
	for (auto node : _Right)
		newset.insert(node);
	return newset;
}

//template <typename T>
//set<T> operator / (const set<T>& _Left, const set<T>& _Right)
//{
//	set<T> newset;
//	for (T node1 : _Left)
//	{
//		bool toAdd = true;
//		for (T node2 : _Right)
//		{
//			if (node1 == node2)
//			{
//				toAdd = false;
//				break;
//			}
//		}
//		if (toAdd)
//			newset.insert(node1);
//	}
//	return newset;
//}