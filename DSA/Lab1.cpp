#include "Lab1.h"

[[noreturn]] void Lab1::t1()
{
	string sequence = "GGGFHHHEEE+=+++_+-//***NNNNNN";

	string ops = "*/-+";
	set<char> s;

	cout << "Исходная строка: " << sequence << endl;

	for (char c : sequence)
		if ('E' <= c && c <= 'N' || ops.find(c) != string::npos)
			s.insert(c);

	cout << "Полученное множество: { ";
	for (auto node : s)
		cout << node << ", ";
	cout << "}";
}
[[noreturn]] void Lab1::t2()
{
	//set<int> s1 = {1, 2, 3, 4, 55};
	//set<int> s2 = {13, 23, 8, 0, 55};
	set<int> s1 = { 1 };
	set<int> s2 = { 1 };
	cout << "Исходные множества:\n";
	cout << "   A: { "; for (auto node : s1) { cout << node << ", "; } cout << "}\n";
	cout << "   B: { "; for (auto node : s2) { cout << node << ", "; } cout << "}\n";
	cout << "Действия по очереди:\n";
	cout << "   A\\B: { "; for (auto node : ExcludeSets(s1, s2)) { cout << node << ", "; } cout << "}\n";
	cout << "   B\\A: { "; for (auto node : ExcludeSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "   AUB: { "; for (auto node : ConcatSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "   A*B: { "; for (auto node : IntersectSets(s2, s1)) { cout << node << ", "; } cout << "}\n";
	cout << "Множества [(A\\B)U(B\\A)] и [(AUB)\\(A*B)] " << (Equals(
		ConcatSets(ExcludeSets(s1, s2), ExcludeSets(s2, s1)),
		ExcludeSets(ConcatSets(s1, s2), IntersectSets(s1, s2))
	) ? "равны" : "неравны");
}