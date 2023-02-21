#pragma once
#include <utility>
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

	int* mBits;
};

