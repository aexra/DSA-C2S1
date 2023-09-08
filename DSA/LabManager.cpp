#include "LabManager.h"

LabManager* LabManager::p_instance = nullptr;

LabManager::LabManager()
{
	om = STDOutputManager::GetInstance();
}
LabManager* LabManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new LabManager();
}

void LabManager::Lab1()
{

}