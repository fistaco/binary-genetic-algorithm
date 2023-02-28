#include "GeneticAlgorithm.h"
#include "Genome.h"
#include <iostream>
#include "BinaryString.h"

template <class genomeType>
GeneticAlgorithm<genomeType>::GeneticAlgorithm(int popSize)
{
	mPopulation = new Genome[popSize];
}

template <class genomeType>
void GeneticAlgorithm<genomeType>::run()
{
	std::cout << "Starting GA.\n";
	return;
}

template <class genomeType>
void GeneticAlgorithm<genomeType>::initialisePopulation(int popSize)
{
	return;
}

template <class genomeType>
void GeneticAlgorithm<genomeType>::evaluateFitness()
{
}

template <class genomeType>
genomeType* GeneticAlgorithm<genomeType>::selectGenomes()
{
	return nullptr;
}

template <class genomeType>
genomeType* GeneticAlgorithm<genomeType>::produceOffspring()
{
	return nullptr;
}

template <class genomeType>
genomeType* GeneticAlgorithm<genomeType>::tournamentSelect()
{
	return nullptr;
}
