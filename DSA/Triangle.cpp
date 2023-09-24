#include "Triangle.h"

std::ostream& operator << (std::ostream& os, const Triangle& tri)
{
	os << "{ " << tri.a << "; " << tri.b << "; " << tri.c << " }";
	return os;
}

std::ofstream& operator << (std::ofstream& os, const Triangle& tri)
{
	os << "{ " << tri.a << "; " << tri.b << "; " << tri.c << " }";
	return os;
}

long double Triangle::__AreaCalc__()
{
	auto p = getPerimeter() / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

long double Triangle::__PerimeterCalc__()
{
	return a + b + c;
}

bool Triangle::isValid()
{
	return (
		a + b > c and
		a + c > b and
		b + c > a
		);
}
