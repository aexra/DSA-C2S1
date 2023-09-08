#include "main.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	LabManager* lm = LabManager::GetInstance();
	lm->ExecuteLab1();

	OutTitle();
	OutSeparator();
	OutEnd();
}

void OutTitle()
{
	cout << "| ������������ ������ �1|" << endl;
	cout << "| ������� �12\t\t|" << endl;
	cout << "| ����� �. �. ���22\t|" << "\n\n\n";
}
void OutEnd()
{
	cout << "\n\n\n";
}
void OutSeparator()
{
	cout << "\n\n\n";
}
