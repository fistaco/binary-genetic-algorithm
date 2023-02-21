#pragma once
#include <utility>
class Genome
{
public:
	Genome(float defaultFitness = 0);

	float getFitness();

	virtual Genome* random();

	virtual Genome* mutate();
	virtual std::pair<Genome*, Genome*> crossover(Genome* other);

private:
	virtual float computeFitness();

	float mFitness;
};

