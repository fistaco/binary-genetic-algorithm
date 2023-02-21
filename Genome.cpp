#include "Genome.h"

Genome::Genome(float defaultFitness)
{
	mFitness = defaultFitness;
}

float Genome::getFitness()
{
	return mFitness;
}

Genome* Genome::random()
{
	return &Genome();
}

float Genome::computeFitness()
{
	return 0.0f;
}
