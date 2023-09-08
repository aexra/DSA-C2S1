#include "STDOutputManager.h"

STDOutputManager* STDOutputManager::p_instance = nullptr;

STDOutputManager::STDOutputManager()
{

}
STDOutputManager* STDOutputManager::GetInstance()
{
	if (p_instance) return p_instance;
	else return p_instance = new STDOutputManager();
}
