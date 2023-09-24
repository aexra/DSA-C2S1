#pragma once

#include "IFigure.h"
#include <iostream>
#include <fstream>
#include <math.h>::sqrt

class Triangle : public IFigure
{
private:
	long double __AreaCalc__() override;
	long double __PerimeterCalc__() override;
public:
	long double a, b, c;

	Triangle(long double _a, long double _b, long double _c) : a(_a), b(_b), c(_c) {};
	bool isValid() override;
	friend std::ostream& operator << (std::ostream& os, const Triangle& tri);
	friend std::ofstream& operator << (std::ofstream& os, const Triangle& tri);
};

