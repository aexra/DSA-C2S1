#include "Lab4.h"

void Lab4::t1()
{
	HRND rnd = new Random();

	LT* a20 = rnd->GetRandFilledArrayT<LT>(20);
	LT* a500 = rnd->GetRandFilledArrayT<LT>(500);
	LT* a1000 = rnd->GetRandFilledArrayT<LT>(1000);
	LT* a3000 = rnd->GetRandFilledArrayT<LT>(3000);
	LT* a5000 = rnd->GetRandFilledArrayT<LT>(5000);
	LT* a10000 = rnd->GetRandFilledArrayT<LT>(10000);

	PrintAry(a20, 20);
}

void Lab4::t2()
{
}

void Lab4::PrintAry(LT* _Right, size_t size)
{
	cout << "[ ";
	for (size_t i = 0; i < size; i++)
	{
		cout << _Right[i] << (i == size - 1 ? " " : ", ");
	}
	cout << "]";
}