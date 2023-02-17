#pragma once
#include "Genome.h"

class GeneticAlgorithm
{
public:
	void run();
private:
	void initialisePopulation(int popSize);
	void evaluateFitness();
	virtual Genome* selectGenomes();
	virtual Genome* produceOffspring();

	Genome* tournamentSelect();
};

