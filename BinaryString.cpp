#include "BinaryString.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

BinaryString::BinaryString(int length, float defaultFitness)
{
    mLength = length;
    mFitness = defaultFitness;

    // Initialise the list of bits with zeros
    mBits.reserve(length);
    for (int i = 0; i < length; i++)
    {
        mBits.push_back(0);
    }
}

float BinaryString::getFitness()
{
    // TODO: Experiment with calling the inherited getFitness() method so we don't have to implement this one at all
    return mFitness;
}

/// <summary>
/// Returns a BinaryString object with a bit string of the given length containing integers randomly set to 0 or 1.
/// </summary>
/// <returns></returns>
BinaryString* BinaryString::random(int length)
{
    BinaryString* binString = new BinaryString(length);
    for (int i = 0; i < length; i++)
    {
        binString->mBits[i] = std::rand() % 2;
    }

    return binString;
}

/// <summary>
/// Randomly modifies this BinaryString by flipping one of its bits.
/// </summary>
/// <returns></returns>
void BinaryString::mutate()
{
    int i = std::rand() % this->mBits.size();
    this->mBits[i] ^= 1;  // 0 XOR 1 == 1; 1 XOR 1 == 0
}

std::pair<Genome*, Genome*> BinaryString::crossover(Genome* other)
{
    return std::pair<BinaryString*, BinaryString*>();
}

Genome* BinaryString::clone()
{
    return nullptr;
}

/// <summary>
/// Prints each of the bits in this BinaryString.
/// </summary>
void BinaryString::print()
{
    for (int bit : mBits)
    {
        std::cout << std::to_string(bit) + " ";
    }
    std::cout << "\n";
}

float BinaryString::computeFitness()
{
    return 0.0f;
}
