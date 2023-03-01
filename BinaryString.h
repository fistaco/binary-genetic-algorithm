#pragma once
#include <utility>
#include <vector>
#include "Genome.h"

class BinaryString : public Genome
{
public:
	BinaryString(int length, float defaultFitness = 0); // Constructor for a binary string of zeros

	float getFitness();

	static BinaryString* random(int length);

	void mutate() override;
	std::pair<Genome*, Genome*> crossover(Genome* other) override;

	Genome* clone() override;

private:
	float computeFitness() override;

	int mLength;
	float mFitness;

	std::vector<int> mBits; // Stores the binary string
};

