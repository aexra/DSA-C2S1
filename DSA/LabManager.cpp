#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| Фомин Н. А. ВПР22\t\t|\n| Вариант №12\t\t\t|";

LabManager::LabManager()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	print(title);
}
LabManager* LabManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new LabManager();
}

void LabManager::_OutLab_(Lab* lab, unsigned short int num, unsigned short int t)
{
	print("| Лабораторная работа №" + to_string(num) + "\t|");
	line(2);

	if (t == 1)
	{
		print("| Задание №1 |\n");
		lab->t1();
		line(2);
	}
	else if (t == 2)
	{
		print("| Задание №2 |\n");
		lab->t2();
		line(3);
	}
	else
	{
		print("| Задание №1 |\n");
		lab->t1();
		line(2);
		print("| Задание №2 |\n");
		lab->t2();
		line(3);
	}
}

void LabManager::ExecuteLab(unsigned short int num, unsigned short int t)
{
	Lab* lab;
	switch (num)
	{
	case 1:
		lab = new Lab1();
		break;
	default:
		print("\n[ERROR\t]   Не найдено реализации лабраторной работы №" + to_string(num));
		return;
	}
	_OutLab_(lab, num, t);
}