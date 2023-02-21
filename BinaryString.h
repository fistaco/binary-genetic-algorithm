#pragma once
#include <utility>
#include <vector>
#include "Genome.h"

class BinaryString : public Genome
{
public:
	BinaryString(int length, float defaultFitness = 0);

	float getFitness();

	static BinaryString* random(int length);

	BinaryString* mutate();
	std::pair<BinaryString*, BinaryString*> crossover(BinaryString* other);

private:
	float mFitness;

	std::vector<int> mBits; // Stores the binary string
};

