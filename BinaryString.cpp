#include "BinaryString.h"
#include <cstdlib>

BinaryString::BinaryString(int length, float defaultFitness)
{
    mFitness = defaultFitness;
    mBits = new int[length]; // Stores the binary string
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

BinaryString* BinaryString::mutate()
{
    return nullptr;
}

std::pair<BinaryString*, BinaryString*> BinaryString::crossover(BinaryString* other)
{
    return std::pair<BinaryString*, BinaryString*>();
}
