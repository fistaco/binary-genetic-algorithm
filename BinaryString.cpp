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

/// <summary>
/// Constructs a new BinaryString by deep copying the given bit array.
/// </summary>
/// <param name="bits"></param>
BinaryString::BinaryString(std::vector<int> bits)
{
    mLength = bits.size();

    mBits.reserve(mLength);
    for (int bit: bits)
    {
        mBits.push_back(bit);
    }

    mFitness = computeFitness();
}

/// <summary>
/// Returns this genome's fitness value. This method assumes that computeFitness() has been called already.
/// </summary>
/// <returns></returns>
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
    BinaryString* clone = new BinaryString(mBits);
    return clone;
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

/// <summary>
/// Computes and returns this BinaryString's fitness as the number of bits set to 1, i.e., its Hamming weight.
/// </summary>
/// <returns></returns>
float BinaryString::computeFitness()
{
    float fitness = 0.0f;
    for (int bit : mBits)
    {
        fitness += (float) bit;
    }

    this->mFitness = fitness;
    return fitness;
}
