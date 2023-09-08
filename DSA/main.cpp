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
	cout << "| ������������ ������ �1|" << endl;
	cout << "| ������� �12\t\t|" << endl;
	cout << "| ����� �. �. ���22\t|" << "\n\n\n";
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
	cout << "| ������� �1 |\n";

	string ops = "*/-+";
	string str = "GGGFHHHEEE+=+++_+-//***NNNNNN";
	set<char> s;

	cout << "�������� ������: " << str << endl;

	for (char c : str)
	{
		if ('E' <= c && c <= 'N' || ops.find(c) != string::npos)
		{
			s.insert(c);
		}
	}

	cout << "���������� ���������: { ";
	for (auto node : s)
	{
		cout << node << ", ";
	}
	cout << "}";
}
void OutSecondTask()
{
	cout << "| ������� �2 |\n";

	//set<int> s1 = {1, 2, 3, 4, 55};
	//set<int> s2 = {13, 23, 8, 0, 55};
	set<int> s1 = {1};
	set<int> s2 = {1};
	cout << "�������� ���������:\n";
	cout << "A: { "; for (auto node : s1) { cout << node << ", "; } cout << "}\n";
	cout << "B: { "; for (auto node : s2) { cout << node << ", "; } cout << "}\n";
	cout << "�������� �� �������:\n";
	cout << "A\\B: { "; for (auto node : ExcludeSets(s1, s2)) { cout << node << ", "; } cout << "}\n";
	cout << "B\\A: { "; for (auto node : ExcludeSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "AUB: { "; for (auto node : ConcatSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "A*B: { "; for (auto node : IntersectSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "��������� [(A\\B)U(B\\A)] � [(AUB)\\(A*B)] " << (Equals(
		ConcatSets(ExcludeSets(s1, s2), ExcludeSets(s2, s1)), 
		ExcludeSets(ConcatSets(s1, s2), IntersectSets(s1, s2))
	)? "�����" : "�������");
}