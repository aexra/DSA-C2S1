#include "Lab1.h"

[[noreturn]] void Lab1::t1()
{
	string sequence = "GGGFHHHEEE+=+++_+-//***NNNNNN";

	string ops = "*/-+";
	set<char> s;

	cout << "�������� ������: " << sequence << endl;

	for (char c : sequence)
		if ('E' <= c && c <= 'N' || ops.find(c) != string::npos)
			s.insert(c);

	cout << "���������� ���������: " << s;
}
[[noreturn]] void Lab1::t2()
{
	//set<int> s1 = {1, 2, 3, 4, 55};
	//set<int> s2 = {13, 23, 8, 0, 55};
	set<int> s1 = { 1 };
	set<int> s2 = { 1 };
	cout << "�������� ���������:\n";
	cout << "   A: { "; for (auto node : s1) { cout << node << ", "; } cout << "}\n";
	cout << "   B: { "; for (auto node : s2) { cout << node << ", "; } cout << "}\n";
	cout << "�������� �� �������:\n";
	cout << "   A\\B: " << ExcludeSets(s1, s2) << "\n";
	cout << "   B\\A: " << ExcludeSets(s2, s1) << "\n";
	cout << "   AUB: " << s2 + s1 << "\n";
	cout << "   A*B: " << IntersectSets(s2, s1) << "\n";
	cout << "��������� [(A\\B)U(B\\A)] � [(AUB)\\(A*B)] " << (Equals(
		ConcatSets(ExcludeSets(s1, s2), ExcludeSets(s2, s1)),
		ExcludeSets(s1 + s2, IntersectSets(s1, s2))
	) ? "�����" : "�������");
}