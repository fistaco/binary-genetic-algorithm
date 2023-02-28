#pragma once
#include <array>
#include "Genome.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize);

	void run();

private:
	virtual void initialisePopulation() = 0;
	void evaluateFitness();
	Genome** selectGenomes();
	Genome** produceOffspring();

	Genome** tournamentSelect(int tournamentSize);

	Genome** mPopulation; // An array of pointers to polymorphic Genome objects
	int mPopSize;
};
