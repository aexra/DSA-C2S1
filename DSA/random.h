#pragma once

#include <time.h>
#include <random>

class Random
{
public:
	Random();
	double randf();
	double randf(double begin, double end);
	int randi(int begin, int end);
};

typedef Random* HRND;
