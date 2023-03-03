#include <cstdlib>
#include <iostream>
#include "BinaryString.h"
#include "CrossoverType.h"
#include "GeneticAlgorithm.h"
#include "Genome.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness)
{
	mPopulation = new Genome*[popSize];
	mPopSize = popSize;
	mGens = gens;
	mCrossoverType = crossoverType;
	mOptimalFitness = optimalFitness;
	mCrossoverRate = crossoverRate;
	mMutationRate = mutationRate;
}

void GeneticAlgorithm::run()
{
	std::cout << "Starting GA.\n";

	this->initialisePopulation();

	int gen = 0;
	float bestFitness = 0.0f;
	Genome* bestGenome = nullptr;

	while (gen < mGens && bestFitness != mOptimalFitness)
	{
		this->evaluateFitness();
		bestGenome = this->findBestGenome();
		bestFitness = bestGenome->getFitness();

		this->selectGenomes(); // TODO: In the method call, select genomes in-place in the population
		this->produceOffspring(mCrossoverType);

		gen++;
	}

	std::cout << "GA terminated after generation " << gen << ".\n";
	std::cout << "Best genome: ";
	bestGenome->print();

	return;
}

void GeneticAlgorithm::evaluateFitness()
{
	for (int i = 0; i < mPopSize; i++)
	{
		mPopulation[i]->computeFitness(); // Should also set each genome's mFitness member variable
	}
}

Genome** GeneticAlgorithm::selectGenomes()
{
	return this->tournamentSelect(3); // TODO: Implement selection method polymorphism
}

/// <summary>
/// Uses the first half of the population as parents to construct offspring by applying crossover and/or mutation with
/// their respective proabilities according to the crossover and mutation rates.
/// </summary>
/// <param name="crossoverType"></param>
/// <returns></returns>
Genome** GeneticAlgorithm::produceOffspring(CrossoverType crossoverType)
{
	int halfPopSize = (int) (mPopSize / 2); // Parents are in the first half of the population, offspring in the second
	float r;

	for (int i = halfPopSize; i < mPopSize; i += 2) // Fill the offspring indices in pairs of two
	{
		Genome* parent0 = mPopulation[rand() % halfPopSize];
		Genome* parent1 = mPopulation[rand() % halfPopSize];

		// Use parents as children in case crossover is not applied
		std::pair<Genome*, Genome*> children = std::pair<Genome*, Genome*>(parent0, parent1);

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		if (r < mCrossoverRate)
		{
			children = parent0->crossover(parent1, crossoverType);
		}

		mPopulation[i] = children.first;
		mPopulation[i + 1] = children.second;
	}

	// Mutate each produced child with a probability equal to the mutation rate
	for (int i = halfPopSize; i < mPopSize; i++)
	{
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		if (r < mMutationRate)
		{
			mPopulation[i]->mutate();
		}
	}

	return nullptr; // TODO: Just use a void function and insert offspring in-place in the population
}

/// <summary>
/// Selects and returns the top performing genomes in the population by repeatedly performing fitness-based tournaments
/// among randomly chosen groups of genomes.
/// 
/// This method assumes larger fitness values are better than smaller ones.
/// </summary>
/// <returns></returns>
Genome** GeneticAlgorithm::tournamentSelect(int tournamentSize = 3)
{
	int numGenomes = (int)(mPopSize / 2); // Note that this always results in an even number of selected parents
	Genome** selectedGenomes = new Genome*[numGenomes];

	for (int i = 0; i < numGenomes; i++)
	{
		// Find the genome with the best fitness in a random group
		Genome* winner = nullptr;
		float best_fitness = -1.0f;
		for (int j = 0; j < tournamentSize; j++)
		{
			Genome* genome = mPopulation[rand() % mPopSize];
			float fitness = genome->getFitness();

			if (fitness > best_fitness)
			{
				winner = genome;
			}
			
			selectedGenomes[i] = winner;
		}
	}

	return selectedGenomes;
}

/// <summary>
/// Returns the genome with the best fitness in the population.
/// </summary>
/// <returns></returns>
Genome* GeneticAlgorithm::findBestGenome()
{
	float bestFitness = 0.0f;
	Genome* bestGenome = mPopulation[0];
	for (int i = 0; i < mPopSize; i++)
	{
		Genome* genome = mPopulation[i];
		float fitness = genome->getFitness();

		if (fitness > bestFitness)
		{
			bestFitness = fitness;
			bestGenome = genome;
		}
	}

	return bestGenome;
}
