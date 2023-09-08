#include "main.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	LabManager* lm = LabManager::GetInstance();
	lm->ExecuteLab1();

	OutTitle();
	OutSeparator();
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
