#pragma once

#include <iostream>
#include <string>

void log(std::string msg, bool endline = 1, std::string prefix = "debug");
void warning(std::string msg);
void error(std::string msg);
