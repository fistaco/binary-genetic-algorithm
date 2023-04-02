#pragma once
#include <array>
#include "CrossoverType.h"
#include "Genome.h"
#include <vector>

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness);

	template <class GenomeType, class... Args>
	void run(Args... genomeInitParams)
	{
		for (int i = 0; i < mPopSize; i++)
		{
			mPopulation[i] = GenomeType::random(genomeInitParams...);
		}
		this->run();
	}

private:
	void run();
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
