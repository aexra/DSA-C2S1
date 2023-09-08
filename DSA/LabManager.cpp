#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| ����� �. �. ���22\t\t|\n| ������� �12\t\t\t|";

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
	print("| ������������ ������ �" + to_string(num) + "\t|");
	line(2);
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
	_OutLab_(lab, 1);
}