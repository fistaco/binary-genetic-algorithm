#pragma once
class Genome
{
public:
	Genome();

	float getFitness();

	virtual Genome random();
private:
	virtual float computeFitness();

	float mFitness;
};

