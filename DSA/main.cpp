#include "main.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	LabManager* lm = LabManager::GetInstance();
	lm->Lab1();

	OutTitle();
	OutFirstTask();
	OutSeparator();
	OutSecondTask();
	OutEnd();
}

void OutTitle()
{
	cout << "| Лабораторная работа №1|" << endl;
	cout << "| Вариант №12\t\t|" << endl;
	cout << "| Фомин Н. А. ВПР22\t|" << "\n\n\n";
}
void OutEnd()
{
	cout << "\n\n\n";
}
void OutSeparator()
{
	cout << "\n\n\n";
}
void OutFirstTask()
{
	cout << "| Задание №1 |\n";

	string ops = "*/-+";
	string str = "GGGFHHHEEE+=+++_+-//***NNNNNN";
	set<char> s;

	cout << "Исходная строка: " << str << endl;

	for (char c : str)
	{
		if ('E' <= c && c <= 'N' || ops.find(c) != string::npos)
		{
			s.insert(c);
		}
	}

	cout << "Полученное множество: { ";
	for (auto node : s)
	{
		cout << node << ", ";
	}
	cout << "}";
}
void OutSecondTask()
{
	cout << "| Задание №2 |\n";

	//set<int> s1 = {1, 2, 3, 4, 55};
	//set<int> s2 = {13, 23, 8, 0, 55};
	set<int> s1 = {1};
	set<int> s2 = {1};
	cout << "Исходные множества:\n";
	cout << "A: { "; for (auto node : s1) { cout << node << ", "; } cout << "}\n";
	cout << "B: { "; for (auto node : s2) { cout << node << ", "; } cout << "}\n";
	cout << "Действия по очереди:\n";
	cout << "A\\B: { "; for (auto node : ExcludeSets(s1, s2)) { cout << node << ", "; } cout << "}\n";
	cout << "B\\A: { "; for (auto node : ExcludeSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "AUB: { "; for (auto node : ConcatSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "A*B: { "; for (auto node : IntersectSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "Множества [(A\\B)U(B\\A)] и [(AUB)\\(A*B)] " << (Equals(
		ConcatSets(ExcludeSets(s1, s2), ExcludeSets(s2, s1)), 
		ExcludeSets(ConcatSets(s1, s2), IntersectSets(s1, s2))
	)? "равны" : "неравны");
}