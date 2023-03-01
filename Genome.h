#pragma once
#include <utility>
class Genome
{
public:
	Genome(float defaultFitness = 0);

	virtual float computeFitness() = 0;
	float getFitness();

	virtual void mutate() = 0;
	virtual std::pair<Genome*, Genome*> crossover(Genome* other) = 0;

	virtual Genome* clone() = 0;
protected:
	float mFitness;
};
