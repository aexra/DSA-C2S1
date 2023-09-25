#include "StringExtensions.h"

vector<string> split(const string& str, const char separator)
{
	vector<string> splitted = {};
	string curSubStr = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == separator)
		{
			if (curSubStr != "")
			{
				splitted.push_back(curSubStr);
				curSubStr = "";
			}
			continue;
		}
		else curSubStr += str[i];
		if (i == str.length() - 1)
		{
			if (curSubStr != "")
			{
				splitted.push_back(curSubStr);
				curSubStr = "";
			}
		}
	}
	return splitted;
}
