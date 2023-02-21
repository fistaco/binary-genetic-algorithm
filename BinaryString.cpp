#include "BinaryString.h"
#include <cstdlib>
#include <vector>

BinaryString::BinaryString(int length, float defaultFitness)
{
    mFitness = defaultFitness;

    // Initialise the list of bits with zeroes
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
BinaryString* BinaryString::mutate()
{
    int i = std::rand() % this->mBits.size();
    this->mBits[i] ^= 1;  // 0 XOR 1 == 1; 1 XOR 1 == 0
}

std::pair<BinaryString*, BinaryString*> BinaryString::crossover(BinaryString* other)
{
    return std::pair<BinaryString*, BinaryString*>();
}
