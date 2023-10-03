#include "Lab3.h"
using namespace SpecialFunctionsForLabs;

void Lab3::t1()
{
	// ��� ��� �������� � �������������� ��������
	typedef int T;

	// ����������
	T arr[10]{};
	T sum = 0;
	int count = 0;

	// ���� �������� � ������ (� �����?)
	for (unsigned int i = 0; i < 10; i++)
	{
		*(arr + i) = input<T>("������� �������� (������ ���� ��� �� �������): ");
	}

	// ���� ����� ���� ���� �� ������ ������ � ��������� �� ����
	for (unsigned int i = 0; i < 10; i++)
	{
		if (*(arr + i) % 2 == 0)
		{
			count++;
			sum += *(arr + i);
		}
	}

	cout << endl;
	cout << "����� ���������, ������� 2: " << sum << endl;
	cout << "���������� ���������, ������� 2: " << count << endl;
}

void Lab3::t2()
{
	const double C = input<double>("������� C: ", "������ �����! ��������� ����: ", true);
	const unsigned int n = input<unsigned int>("������� ������ ����������� �������: ");

	double* arr = new double[n];
	unsigned int count = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		*(arr + i) = input<double>("������� " + to_string(i+1) + "-� ������� �������: ", "������ �����! ��������� ����: ", true);
		count += *(arr + i) > C;
	}

	cout << endl << "���������� ���������, ������� �: " << count;
}
