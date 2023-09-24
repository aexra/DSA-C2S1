#include "IFigure.h"

long double IFigure::getArea()
{
	if (!isValid()) return -1;
	return (area == -1? area = __AreaCalc__() : area);
}

long double IFigure::getPerimeter()
{
	return (perimeter == -1 ? perimeter = __PerimeterCalc__() : perimeter);
}