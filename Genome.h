#pragma once
#include <utility>
#include "CrossoverType.h"

class Genome
{
public:
	Genome(float defaultFitness = 0);

	virtual float computeFitness() = 0;
	virtual float getFitness();

	virtual void mutate() = 0;
	virtual std::pair<Genome*, Genome*> crossover(Genome* other, CrossoverType crossoverType) = 0;

	virtual Genome* clone() = 0;

	virtual void print() = 0;
protected:
	float mFitness;
};
