#include "Lab2.h"

using namespace SpecialFunctionsForLabs;

#define MANUAL_FILE_CREATION 1
#define DIGITS_RANDOMLY_CREATED 10
#define MAX_RANDOM_VALUE 3.0
#define MIN_RANDOM_VALUE -3.0

void Lab2::t1()
{
	if (!MANUAL_FILE_CREATION)
	{

	}

	log("ќткрытие файла дл€ чтени€ данных...");
	ifstream ifile("resources\\Lab2\\triangles.txt");
	if (!ifile.good())
	{
		log("‘айл не найден. «авершение процедуры...");
		return;
	}
	log("‘айл открыт");

	log("ѕарсинг текста в треугольники...");
	vector<Triangle> vec = parseTrianglesFile(ifile);
	ifile.close();
	log("ѕарсинг завершен");

	ofstream ofile("resources\\Lab2\\output1.txt", ios_base::app);
	log("‘айл дл€ записи результата создан и открыт");
	log("«аполнение файла...");
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
			ofile << "“реугольник невозможен";
			cout << "\t“реугольник невозможен";
		}
		ofile << endl;
		cout << endl;
	}
	ofile << "\n\n";
	log("‘айл заполнен");
	ofile.close();
	log("ѕоток записи закрыт");

	if (input("–ешить ƒоѕоЋн»т≈л№нќе задание???  [y/n]   ->   ", "") != "y") return;
	cout << "\nƒќѕќЋЌ»“≈Ћ№Ќќ≈ «јƒјЌ»≈\n\n";

	cout << "Ётап 1)";
	ofstream odopfile("./resources/Lab2/output1.txt", ios_base::app);
	HRND rnd = new Random();
	for (unsigned int i = 0; i < DIGITS_RANDOMLY_CREATED; i++) {
		odopfile << rnd->randf(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE) << endl;
	}
	odopfile << "\n\n";
	odopfile.close();
	ifstream idopfile("./resources/Lab2/output1.txt");
	string buffer;
	size_t count = 0;
	while (getline(idopfile, buffer)) {
		if (is_double(buffer) && stod(buffer) < 0) count++;
	}
	cout << " ƒобавил в файл рандомные числа -> ќтрицательных: " + to_string(count) << endl;
	idopfile.close();

	cout << "Ётап 2) ";
	idopfile = ifstream("./resources/Lab2/output1.txt");
	char ch = input("¬ведите вставл€емый символ: ", "")[0];
	buffer = "";
	string text;
	while (getline(idopfile, buffer)) text += buffer + '\n';
	size_t len = text.length();
	int ri = rnd->randi(0, len - 1);
	text.insert(text.begin() + ri, ch);
	idopfile.close();
	odopfile = ofstream("./resources/Lab2/output1.txt", ios_base::trunc);
	odopfile << text;
	cout << "¬ставил в исходный файл букву [" << ch << "] на место по индексу (символа) [" << ri << "]\n";
}

void Lab2::t2()
{
	ofstream ofile("./resources/Lab2/digits.txt", ios_base::trunc);
	log("—оздан и открыт дл€ записи файл <digits.txt>");
	
	HRND hrnd = new Random();
	long double sum = 0;
	for (unsigned int i = 0; i < DIGITS_RANDOMLY_CREATED; i++) {
		double digit = hrnd->randf(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE);
		sum += digit;
		ofile << digit << endl;
	}
	log("—генерировано и записано в файл [" + to_string(DIGITS_RANDOMLY_CREATED) + "] значений");

	long double avarage = sum / (double)DIGITS_RANDOMLY_CREATED;
	log("—реднее арифметическое сгенерированных чисел: " + to_string(avarage), 1, "INFO-R");

	ifstream ifile("./resources/Lab2/digits.txt");
	log("ќткрыт поток дл€ чтени€ файла <digits.txt>");

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
	log("—реди сгенерированных чисел [" + to_string(count) + "] меньше среднего арифметического всех этих чисел", 1, "INFO-R");

	string result = input("ќтобразить подход€щие числа? [y/n]   ->   ", "");
	if (result == "y" || result == "Y")
	{
		for (unsigned int i = 0; i < count; i++)
			cout << i+1 << ". " << good_digits[i] << endl;
	}

	ofile.close();
	log("ѕоток записи в файл <digits.txt> закрыт");

	if (input("\n\n–ешить ƒоѕоЋн»т≈л№нќе задание???  [y/n]   ->   ", "") != "y") return;
	cout << "ƒќѕќЋЌ»“≈Ћ№Ќќ≈ «јƒјЌ»≈\n\n";
	cout << "\nЁтап 1) ";
	unsigned int n = input<unsigned int>("¬ведите номер искомой строки: ");
	ifstream idopfile("./resources/Lab2/digits.txt");
	buffer = "";
	size_t k = 1;
	while (getline(idopfile, buffer)) {
		if (k == n)
		{
			cout << "»скома€ строка: \n" << n << ". " << buffer << endl;
			break;
		}
		k++;
	}
	if (k != n) cout << "—трока с таким номером не найдена! ѕодумайте над своим поведением.";
	idopfile.close();

	cout << "\n\nЁтап 2) ";
	string sub = input("¬ведите искомую подстроку: ", "");
	idopfile = ifstream("./resources/Lab2/digits.txt");
	buffer = "";
	size_t string_n = 1;
	bool found = 0;
	while (getline(idopfile, buffer)) {
		for (size_t i = 0; i < buffer.length(); i++) {
			string sub_tmp = "";
			bool flag = 1;
			for (size_t j = 0; j < sub.length(); j++) {
				if (i+j > buffer.length() - 1)
				{
					flag = 0;
					break;
				}
				if (buffer[i+j] != sub[j]) { flag = 0; break; }
			}
			if (flag) {
				cout << "ѕодстрока найдена: " << buffer << " (" << string_n << ", " << i + 1 << ")" << endl;
				found = 1;
				idopfile.close();
				break;
			}
		}
		string_n++;
	}
	idopfile.close();
	if (!found) cout << "ѕодстрока не найдена. ”вы.";

	cout << "\n\nЁтап 3) ";
	idopfile = ifstream("./resources/Lab2/digits.txt");
	buffer = "";
	set<string> words;
	while (getline(idopfile, buffer)) {
		vector<string> splitted = split(buffer);
		for (const string& str : splitted) { words.insert(str); }
	}
	idopfile.close();
	cout << "”никальные слова: " << words << "\n\n";
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
