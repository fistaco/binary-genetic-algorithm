#include <iostream>
#include <string>
#include "BinaryString.h"
#include "CrossoverType.h"
#include "GeneticAlgorithm.h"
#include "Genome.h"

int main()
{
    int popSize = 8;
    int gens = 30;
    auto crossoverType = CrossoverType::OnePoint;
    float crossoverRate = 0.5f;
    float mutRate = 0.8f;
    float maxFitness = 8.0f;

    auto ga = GeneticAlgorithm(popSize, gens, crossoverType, crossoverRate, mutRate, maxFitness);
    ga.run<BinaryString>(8);
}
