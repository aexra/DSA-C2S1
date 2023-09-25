#pragma once

#include <time.h>
#include <random>

class Random
{
public:
	Random();
	double randf();
	double randf(double begin, double end);
};

typedef Random* HRND;
