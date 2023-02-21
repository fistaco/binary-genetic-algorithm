#include "Genome.h"

Genome::Genome(float defaultFitness)
{
	mFitness = defaultFitness;
}

float Genome::getFitness()
{
	return 0.0f;
}

Genome Genome::random()
{
	return Genome();
}

float Genome::computeFitness()
{
	return 0.0f;
}
