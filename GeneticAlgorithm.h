#pragma once
#include <array>
#include "CrossoverType.h"
#include "Genome.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness);

	void run();

private:
	virtual void initialisePopulation() = 0;
	void evaluateFitness();
	void selectGenomes();
	void produceOffspring(CrossoverType crossoverType);

	void tournamentSelect(int tournamentSize);

	Genome* findBestGenome();

	Genome** mPopulation; // An array of pointers to polymorphic Genome objects
	int mPopSize;

	int mGens; // The maximum number of generations
	float mOptimalFitness;
	CrossoverType mCrossoverType;
	float mCrossoverRate;
	float mMutationRate;
};
