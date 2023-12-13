#include "main.h"
void main()
{
	LabManager* lm = LabManager::GetInstance();
	lm->ExecuteLab(6, 1);
}