#pragma once


// BUILT-IN INCLUSIONS
#include <set>
#include <iostream>

// CUSTOM FILES INCLUSIONS
#include "Lab.h"

// USES
using namespace std;

/*			LAB CLASS				*/

class Lab1 : public Lab
{
#pragma region Private
private:
	template <typename T>
	set<T> ConcatSets(const set<T>& _Left, const set<T>& _Right)
	{
		set<T> newset;
		for (auto node : _Left)
			newset.insert(node);
		for (auto node : _Right)
			newset.insert(node);
		return newset;
	}

	template <typename T>
	set<T> IntersectSets(const set<T>& _Left, const set<T>& _Right)
	{
		set<T> newset;
		for (T node1 : _Left)
			for (T node2 : _Right)
				if (node1 == node2)
				{
					newset.insert(node1);
					break;
				}
		return newset;
	}

	template <typename T>
	set<T> ExcludeSets(const set<T>& _Left, const set<T>& _Right)
	{
		set<T> newset;
		for (T node1 : _Left)
		{
			bool toAdd = true;
			for (T node2 : _Right)
			{
				if (node1 == node2)
				{
					toAdd = false;
					break;
				}
			}
			if (toAdd)
				newset.insert(node1);
		}
		return newset;
	}

	template <typename T>
	bool Equals(const set<T>& _Left, const set<T>& _Right)
	{
		bool isEquals = true;
		for (T node1 : _Left)
			for (T node2 : _Right)
				if (node1 != node2)
					isEquals = false;
		return isEquals;
	}
#pragma endregion

#pragma region Public
public:
	[[noreturn]] void t1();
	[[noreturn]] void t2();
#pragma endregion
};
