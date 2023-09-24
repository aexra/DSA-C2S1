#include "Lab2.h"
#include "StringExtensions.h"

#define MANUAL_FILE_CREATION 1

void Lab2::t1()
{
	if (!MANUAL_FILE_CREATION)
	{

	}

	/*ifstream file("triangles.txt");*/
	vector<string> vec = split(string("1 0 1"));
	for (string str : vec)
	{
		cout << str << '\n';
	}
}

void Lab2::t2()
{
}

vector<Triangle> Lab2::parseTrianglesFile(ifstream& ifs)
{
	return vector<Triangle>();
}
