#pragma once
#include <utility>
#include <vector>
#include "CrossoverType.h"
#include "Genome.h"

class BinaryString : public Genome
{
public:
	BinaryString(int length, float defaultFitness = 0); // Constructor for a binary string of zeros
	BinaryString(std::vector<int> bits);

	float computeFitness() override;
	float getFitness();

	static BinaryString* random(int length);

	void mutate() override;
	std::pair<Genome*, Genome*> crossover(Genome* other, CrossoverType crossoverType) override;

	Genome* clone() override;

	void print();

private:
	int mLength;
	float mFitness;

	std::vector<int> mBits; // Stores the binary string
};

