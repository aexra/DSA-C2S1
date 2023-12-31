#pragma once

#include <string>
#include <iostream>
using namespace std;

namespace SpecialFunctionsForLabs {
	bool is_int(string str);
	bool is_double(string str, bool canBeInt = false);
	bool is_char(string str);
	bool is_natural(string str);
	string dtos(double value, unsigned int absolutePresision = 2);
	double round(double value, unsigned int precision);

	template<typename T>
	T input(string _Message = "", string _DefaultErrorMessage = "������ �����! ��������� ����: ", bool _FlagArg = 0)
	{
		cout << _Message;
		string input;
		getline(cin, input);

		if (is_same<T, unsigned int>::value) {
			if (!_FlagArg) {
				while (!(is_int(input) && stoi(input) > 0)) {
					cout << _DefaultErrorMessage;
					getline(cin, input);
				}
			}
			else {
				while (!(is_int(input) && stoi(input) >= 0)) {
					cout << _DefaultErrorMessage;
					getline(cin, input);
				}
			}
			return stoi(input);
		}
		if (is_same<T, int>::value) {
			while (!is_int(input)) {
				cout << _DefaultErrorMessage;
				getline(cin, input);
			}
			return stoi(input);
		}
		else if (is_same<T, float>::value) {
			while (!is_double(input, _FlagArg)) {
				cout << _DefaultErrorMessage;
				getline(cin, input);
			}
			return stof(input);  // ��� setlocale(LC_NUMERIC, "C")
		}
		else if (is_same<T, double>::value) {
			while (!is_double(input, _FlagArg)) {
				cout << _DefaultErrorMessage;
				getline(cin, input);
			}
			return stod(input);  // ��� setlocale(LC_NUMERIC, "C")
		}
		else if (is_same<T, char>::value) {
			while (!is_char(input)) {
				cout << _DefaultErrorMessage;
				getline(cin, input);
			}
			return input[0];
		}
		/*else if (is_same<T, string>::value) {
			string buf;
			getline(cin, buf);
			return buf;
		}*/

		return NULL;
	}

}