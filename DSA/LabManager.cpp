#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| ����� �. �. ���22\t|\n| ������� �12\t\t|";

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
	print("| ������� �1 |\n");
	lab->t1();
	line(2);
	print("| ������� �2 |\n");
	lab->t2();
	line(3);
}

void LabManager::ExecuteLab1()
{
	Lab* lab = new Lab1();
	_OutLab_(lab);
}