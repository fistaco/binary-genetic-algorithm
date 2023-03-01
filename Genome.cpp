#include "Genome.h"

Genome::Genome(float defaultFitness)
{
	mFitness = defaultFitness;
}

float Genome::getFitness()
{
	return mFitness;
}

std::pair<Genome*, Genome*> Genome::crossover(Genome* other)
{
	return std::pair<Genome*, Genome*>();
}
