#include "UltraCoolNamespace.h"

bool SpecialFunctionsForLabs::is_int(string str)
{
	if (str.length() < 1) return false;
	if (str.length() > 9) return false;

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	for (char c : str) {
		if (!('0' <= c && c <= '9' || c == '-')) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_double(string str, bool canBeInt)
{
	if (str.length() < 1) return false;

	if (canBeInt && SpecialFunctionsForLabs::is_int(str)) return true;
	if (!SpecialFunctionsForLabs::is_int(str) && find(str.begin(), str.end(), '.') == str.end()) return false;

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	if (count(str.begin(), str.end(), '.') > 1) return false;
	if (count(str.begin(), str.end(), '.') > 0 && (str[0] == '.' || str[0] == '-' && str[1] == '.' || str.back() == '.')) return false;

	if (str.substr(0, str.find('.')).length() > 9 || str.substr(str.find('.'), str.length() - 1).length() > 15);

	for (char c : str) {
		if (!('0' <= c && c <= '9' || c == '-' || c == '.')) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_natural(string str)
{
	return (is_int(str) && stoi(str) > 0);
}
double SpecialFunctionsForLabs::round(double value, unsigned int precision)
{
	double k = pow(10, precision);
	return (int)(value * k + 0.5) / k;
}
bool SpecialFunctionsForLabs::is_char(string str)
{
	return (str.length() == 1);
}
string SpecialFunctionsForLabs::dtos(double value, unsigned int absolutePresision)
{
	string str = to_string(value);
	unsigned int precision = min(absolutePresision + str.find('.'), str.length());
	for (int i = precision; i > 1; i--)
	{
		if (str[i] == '0') precision--;
		else break;
	}
	return str.substr(0, precision + 1);
}