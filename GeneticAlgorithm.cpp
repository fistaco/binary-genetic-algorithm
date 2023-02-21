#include "GeneticAlgorithm.h"
#include "Genome.h"
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm(int popSize)
{
	mPopulation = new Genome[popSize];
}

void GeneticAlgorithm::run()
{
	std::cout << "Starting GA.\n";
	return;
}

void GeneticAlgorithm::initialisePopulation(int popSize)
{
}

void GeneticAlgorithm::evaluateFitness()
{
}

Genome* GeneticAlgorithm::selectGenomes()
{
	return nullptr;
}

Genome* GeneticAlgorithm::produceOffspring()
{
	return nullptr;
}

Genome* GeneticAlgorithm::tournamentSelect()
{
	return nullptr;
}
