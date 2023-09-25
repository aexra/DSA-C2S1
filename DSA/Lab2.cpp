#include "Lab2.h"
#include "StringExtensions.h"

#define MANUAL_FILE_CREATION 1
#define DIGITS_RANDOMLY_CREATED 10000
#define MAX_RANDOM_VALUE 1000000.0
#define MIN_RANDOM_VALUE -1000000.0

void Lab2::t1()
{
	if (!MANUAL_FILE_CREATION)
	{

	}

	log("Открытие файла для чтения данных...");
	ifstream ifile("resources\\Lab2\\triangles.txt");
	if (!ifile.good())
	{
		log("Файл не найден. Завершение процедуры...");
		return;
	}
	log("Файл открыт");

	log("Парсинг текста в треугольники...");
	vector<Triangle> vec = parseTrianglesFile(ifile);
	ifile.close();
	log("Парсинг завершен");

	ofstream ofile("resources\\Lab2\\output1.txt", ios_base::app);
	log("Файл для записи результата создан и открыт");
	log("Заполнение файла...");
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
			ofile << "Треугольник невозможен";
			cout << "\tТреугольник невозможен";
		}
		ofile << endl;
		cout << endl;
	}
	ofile << "\n\n";
	log("Файл заполнен");
	ofile.close();
	log("Поток записи закрыт");
}

void Lab2::t2()
{
	ofstream ofile("./resources/Lab2/digits.txt", ios_base::trunc);
	log("Создан и открыт для записи файл <digits.txt>");
	
	HRND hrnd = new Random();
	for (unsigned int i = 0; i < DIGITS_RANDOMLY_CREATED; i++) {
		ofile << hrnd->randf(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE) << endl;
	}
	log("Сгенерировано и записано в файл [" + to_string(DIGITS_RANDOMLY_CREATED) + "] значений");

	ofile.close();
	log("Поток записи в файл <digits.txt> закрыт");
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
