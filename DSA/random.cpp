#include "random.h"

Random* Random::p_instance = nullptr;

Random::Random()
{
	srand(time(0));
}

Random* Random::GetInstance()
{
	return Random::p_instance ? Random::p_instance : Random::p_instance = new Random();
}

double Random::randf()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

double Random::randf(double begin, double end)
{
	return begin + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (end - begin)));
}

int Random::randi(int begin, int end)
{
	return begin + (rand() % static_cast<int>(end - begin + 1));
}
