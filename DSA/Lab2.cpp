#include "Lab2.h"
#include "StringExtensions.h"

#define MANUAL_FILE_CREATION 1

void Lab2::t1()
{
	if (!MANUAL_FILE_CREATION)
	{

	}

	ifstream ifile("resources\\triangles.txt");
	if (!ifile.good())
	{
		cout << "Файл со сторонами треугольников не найден!";
		return;
	}

	vector<Triangle> vec = parseTrianglesFile(ifile);
	ifile.close();

	ofstream ofile("resources\\output1.txt", ios_base::app);

	for (auto& tri : vec)
	{
		ofile << tri << "\t : ";
		if (tri.isValid())
			ofile << tri.getArea();
		else
			ofile << "Треугольник невозможен.";
		ofile << endl;
	}
	ofile << "\n\n";
	ofile.close();
}

void Lab2::t2()
{
}

vector<Triangle> Lab2::parseTrianglesFile(ifstream& ifs)
{
	vector<Triangle> vec;
	while (!ifs.eof())
	{
		string s;
		getline(ifs, s);
		vector<double> sides;
		for (string& str : split(s)) sides.push_back(stod(str));
		if (sides.size() != 3) continue;
		vec.push_back(Triangle(sides[0], sides[1], sides[2]));
	}
	return vec;
}
