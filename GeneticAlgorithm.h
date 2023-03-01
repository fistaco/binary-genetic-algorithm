#pragma once
#include <array>
#include "CrossoverType.h"
#include "Genome.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType);

	void run();

private:
	virtual void initialisePopulation() = 0;
	void evaluateFitness();
	Genome** selectGenomes();
	Genome** produceOffspring(CrossoverType crossoverType);

	Genome** tournamentSelect(int tournamentSize);

	Genome** mPopulation; // An array of pointers to polymorphic Genome objects
	int mPopSize;

	int mGens; // The maximum number of generations
	CrossoverType mCrossoverType;
};
