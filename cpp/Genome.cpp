#include "Genome.h"

Genome::Genome(float defaultFitness)
{
	mFitness = defaultFitness;
}

/// <summary>
/// Returns this genome's fitness value. This method assumes that computeFitness() has been called already.
/// </summary>
/// <returns></returns>
float Genome::getFitness()
{
	return mFitness;
}
