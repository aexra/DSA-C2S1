#pragma once

class IFigure
{
public:
	long double getArea();
	long double getPerimeter();

	virtual bool isValid() = 0;
protected:
	long double area = -1, perimeter = -1;

	virtual long double __AreaCalc__() = 0;
	virtual long double __PerimeterCalc__() = 0;
};