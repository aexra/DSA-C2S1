#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;
string LabManager::title = "| ����� �. �. ���22\t|\n| ������� �12\t\t|";

LabManager::LabManager()
{
	om = STDOutputManager::GetInstance();
}
LabManager* LabManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new LabManager();
}

void LabManager::ExecuteLab1()
{
	Lab* lab = new Lab1();
	_OutLab_(lab);
}