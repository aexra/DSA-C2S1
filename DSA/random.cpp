#include "random.h"

Random::Random()
{
	srand(time(0));
}

double Random::randf()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

double Random::randf(double begin, double end)
{
	return begin + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (end - begin)));
}
