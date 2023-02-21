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
	return new Genome();
}

Genome* Genome::mutate()
{
	return nullptr;
}

std::pair<Genome*, Genome*> Genome::crossover(Genome* other)
{
	return std::pair<Genome*, Genome*>();
}

float Genome::computeFitness()
{
	return 777.0f;
}
