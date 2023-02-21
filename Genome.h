#pragma once
class Genome
{
public:
	Genome(float defaultFitness = 0);

	float getFitness();

	virtual Genome* random();

private:
	virtual float computeFitness();

	float mFitness;
};

