#pragma once
#include "Genome.h"

template <class genomeType>
class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize);

	void run();

private:
	void initialisePopulation(int popSize);
	void evaluateFitness();
	genomeType* selectGenomes();
	genomeType* produceOffspring();

	genomeType* tournamentSelect();

	genomeType* mPopulation;
};

