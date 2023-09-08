#include "main.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	LabManager* lm = LabManager::GetInstance();
	lm->ExecuteLab1();
}