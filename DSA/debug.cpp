#include "debug.h"

void log(std::string msg, bool endline, std::string prefix)
{
	std::cout << "[" << prefix << "\t]" << " " << msg << (endline? "\n" : "");
}

void warning(std::string msg)
{
	std::cout << "[warning]" << " " << msg << std::endl;
}

void error(std::string msg)
{
	std::cout << "[error]" << " " << msg << std::endl;
}
