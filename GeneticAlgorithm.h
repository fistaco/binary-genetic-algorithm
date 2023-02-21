#pragma once
#include "Genome.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize);

	void run();
private:
	void initialisePopulation(int popSize);
	void evaluateFitness();
	virtual Genome* selectGenomes();
	virtual Genome* produceOffspring();

	Genome* tournamentSelect();

	Genome* mPopulation;
};

