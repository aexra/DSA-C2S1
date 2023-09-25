#include "Lab2.h"
#include "StringExtensions.h"

#define MANUAL_FILE_CREATION 1
#define DIGITS_RANDOMLY_CREATED 10
#define MAX_RANDOM_VALUE 3.0
#define MIN_RANDOM_VALUE -3.0

void Lab2::t1()
{
	if (!MANUAL_FILE_CREATION)
	{

	}

	log("�������� ����� ��� ������ ������...");
	ifstream ifile("resources\\Lab2\\triangles.txt");
	if (!ifile.good())
	{
		log("���� �� ������. ���������� ���������...");
		return;
	}
	log("���� ������");

	log("������� ������ � ������������...");
	vector<Triangle> vec = parseTrianglesFile(ifile);
	ifile.close();
	log("������� ��������");

	ofstream ofile("resources\\Lab2\\output1.txt", ios_base::app);
	log("���� ��� ������ ���������� ������ � ������");
	log("���������� �����...");
	for (auto& tri : vec)
	{
		ofile << tri << "\t => ";
		cout << tri << "\t => ";
		if (tri.isValid())
		{
			ofile << "P=" << tri.getPerimeter() << "\tS=" << tri.getArea();
			cout << "\tP=" << tri.getPerimeter() << "\tS=" << tri.getArea();
		}
		else
		{
			ofile << "����������� ����������";
			cout << "\t����������� ����������";
		}
		ofile << endl;
		cout << endl;
	}
	ofile << "\n\n";
	log("���� ��������");
	ofile.close();
	log("����� ������ ������");
}

void Lab2::t2()
{
	ofstream ofile("./resources/Lab2/digits.txt", ios_base::trunc);
	log("������ � ������ ��� ������ ���� <digits.txt>");
	
	HRND hrnd = new Random();
	long double sum = 0;
	for (unsigned int i = 0; i < DIGITS_RANDOMLY_CREATED; i++) {
		double digit = hrnd->randf(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE);
		sum += digit;
		ofile << digit << endl;
	}
	log("������������� � �������� � ���� [" + to_string(DIGITS_RANDOMLY_CREATED) + "] ��������");

	long double avarage = sum / (double)DIGITS_RANDOMLY_CREATED;
	log("������� �������������� ��������������� �����: " + to_string(avarage), 1, "INFO-R");

	ifstream ifile("./resources/Lab2/digits.txt");
	log("������ ����� ��� ������ ����� <digits.txt>");

	unsigned int count = 0;
	string buffer;
	vector<double> good_digits;
	while (getline(ifile, buffer)) {
		double digit = stod(buffer);
		if (digit < avarage)
		{
			count++;
			good_digits.push_back(digit);
		}
	}
	log("����� ��������������� ����� [" + to_string(count) + "] ������ �������� ��������������� ���� ���� �����", 1, "INFO-R");

	string result = input("���������� ���������� �����? [y/n]   ->   ", "");
	if (result == "y" || result == "Y")
	{
		for (unsigned int i = 0; i < count; i++)
			cout << i+1 << ". " << good_digits[i] << endl;
	}

	ofile.close();
	log("����� ������ � ���� <digits.txt> ������");
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
