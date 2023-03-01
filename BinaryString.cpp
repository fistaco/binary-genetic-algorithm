#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "BinaryString.h"
#include "CrossoverType.h"

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
/// Returns this BinaryString's internal bit array.
/// </summary>
/// <returns></returns>
std::vector<int> BinaryString::getBits()
{
    return mBits;
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

/// <summary>
/// Performs crossover by taking
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
std::pair<Genome*, Genome*> BinaryString::crossover(Genome* other, CrossoverType crossoverType)
{
    return std::pair<BinaryString*, BinaryString*>();
}

/// <summary>
/// Produces and returns two BinaryString children where the first is formed by taking all bits from this BinaryString
/// up to a random point and the remaining bits from the given other parent after that cutoff point. The second child
/// consists of the complementing parent segments.
/// </summary>
/// <param name="other"></param>
/// <param name="crossoverType"></param>
/// <returns></returns>
std::pair<Genome*, Genome*> BinaryString::onePointCrossover(BinaryString* other)
{
    std::vector<int> childBits0;
    std::vector<int> childBits1;
    std::vector<int> other_parent_bits = other->getBits();

    int cutoff = std::rand() % mLength;
    for (int i = 0; i < mLength; i++)
    {
        childBits0.push_back(i < cutoff ? this->mBits[i] : other_parent_bits[i]);
        childBits1.push_back(i < cutoff ? other_parent_bits[i] : this->mBits[i]);
    }

    BinaryString* c0 = new BinaryString(childBits0);
    BinaryString* c1 = new BinaryString(childBits1);

    return std::pair<Genome*, Genome*>(c0, c1);
}

/// <summary>
/// Produces and returns two BinaryString children formed by iterating over each bit array index and assigning one
/// child the bit at that position in the first parent while assigning the other child the other parent's bit.
/// </summary>
/// <param name="other"></param>
/// <param name="crossoverType"></param>
/// <returns></returns>
std::pair<Genome*, Genome*> BinaryString::uniformCrossover(BinaryString* other)
{
    std::vector<int> childBits0;
    std::vector<int> childBits1;
    std::vector<int> other_parent_bits = other->getBits();

    for (int i = 0; i < mLength; i++)
    {
        // Randomly choose a bit from this BinaryString and the other parent
        int r = std::rand() % 2;
        childBits0.push_back(r == 0 ? this->mBits[i] : other_parent_bits[i]);
        childBits1.push_back(r == 1 ? this->mBits[i] : other_parent_bits[i]);
    }

    BinaryString* c0 = new BinaryString(childBits0);
    BinaryString* c1 = new BinaryString(childBits1);

    return std::pair<Genome*, Genome*>(c0, c1);
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
