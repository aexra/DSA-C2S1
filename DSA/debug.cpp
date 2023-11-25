#include "debug.h"

void log(std::string msg, bool endline, std::string prefix)
{
	std::cout << "[" << prefix << "]" << " " << msg << (endline? "\n" : "");
}

void warning(std::string msg)
{
	std::cout << "[WARNING]" << " " << msg << std::endl;
}

void error(std::string msg)
{
	std::cout << "[ERROR\t]" << " " << msg << std::endl;
}
