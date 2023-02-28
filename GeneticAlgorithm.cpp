#include "GeneticAlgorithm.h"
#include "Genome.h"
#include <cstdlib>
#include <iostream>
#include "BinaryString.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize)
{
	mPopulation = new Genome*[popSize];
	mPopSize = popSize;
}

void GeneticAlgorithm::run()
{
	std::cout << "Starting GA.\n";
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

Genome** GeneticAlgorithm::produceOffspring()
{
	return nullptr;
}

/// <summary>
/// Selects and returns the top performing genomes in the population by repeatedly performing fitness-based tournaments
/// among randomly chosen groups of genomes.
/// 
/// This method assumes larger fitness values are better than smaller ones.
/// </summary>
/// <returns></returns>
Genome** GeneticAlgorithm::tournamentSelect(int tournamentSize)
{
	int numGenomes = (int)(mPopSize / 2);
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
