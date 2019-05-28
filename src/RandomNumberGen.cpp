#include <RandomNumberGen.h>

uint64_t RandomNumberGen::getSeed()
{
    std::random_device rdev;
    // create a seed inside class
    uint64_t seed = (uint64_t (rdev()) << 32) | rdev();
    return seed;
}

float RandomNumberGen::getUniformValue()
{
       m_rng.seed(m_sequenceIndex,m_sequenceStartingPoint);
       return m_rng.nextFloat();
}

double RandomNumberGen::getUniformValueDouble()
{
       m_rng.seed(m_sequenceIndex,m_sequenceStartingPoint);
       return m_rng.nextDouble();
}







