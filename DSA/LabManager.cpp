#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| Фомин Н. А. ВПР22\t|\n| Вариант №12\t\t|";

LabManager::LabManager()
{
	print(title);
	line(2);
}
LabManager* LabManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new LabManager();
}

void LabManager::_OutLab_(Lab* lab)
{
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
	_OutLab_(lab);
}