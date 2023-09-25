#include "STDOutputManager.h"

void print(std::string msg, std::string end)
{
	std::cout << msg << end;
}
void line(unsigned int n = 1)
{
	for (unsigned int i = 0; i < n; i++)
		std::cout << std::endl;
}

std::string input(std::string msg, std::string end)
{
	std::cout << msg << end;
	std::string buffer;
	std::cin >> buffer;
	return buffer;
}
