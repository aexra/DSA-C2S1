#include "main.h"
void main()
{
	LabManager* lm = LabManager::GetInstance();
	lm->ExecuteLab(4);
	//lm->ExecuteLab(5, 1);
}