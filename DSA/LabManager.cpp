#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| Фомин Н. А. ВПР22\t\t|\n| Вариант №12\t\t\t|";

LabManager::LabManager()
{
	print(title);
}
LabManager* LabManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new LabManager();
}

void LabManager::_OutLab_(Lab* lab, unsigned short int num)
{
	print("| Лабораторная работа №" + to_string(num) + "\t|");
	line(2);
	print("| Задание №1 |\n");
	lab->t1();
	line(2);
	print("| Задание №2 |\n");
	lab->t2();
	line(3);
}

void LabManager::ExecuteLab1()
{
	Lab* lab = new Lab1();
	_OutLab_(lab, 1);
}