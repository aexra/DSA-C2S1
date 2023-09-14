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

	cout << "Полученное множество: " << s;
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
	cout << "   A\\B: " << ExcludeSets(s1, s2) << "\n";
	cout << "   B\\A: " << ExcludeSets(s2, s1) << "\n";
	cout << "   AUB: " << s2 + s1 << "\n";
	cout << "   A*B: " << IntersectSets(s2, s1) << "\n";
	cout << "Множества [(A\\B)U(B\\A)] и [(AUB)\\(A*B)] " << (Equals(
		ConcatSets(ExcludeSets(s1, s2), ExcludeSets(s2, s1)),
		ExcludeSets(s1 + s2, IntersectSets(s1, s2))
	) ? "равны" : "неравны");
}