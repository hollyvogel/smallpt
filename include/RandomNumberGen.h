#ifndef RANDOMNUMBERGEN_H_
#define RANDOMNUMBERGEN_H_

#include <memory>
#include <pcg32.h>
#include <Util.h>


class RandomNumberGen
{

public:
    void setIndex (uint64_t _index){m_sequenceIndex = _index;}
    void setSequenceStartingPoint(uint64_t _startingPoint){m_sequenceStartingPoint = _startingPoint;}
    uint64_t getSeed();
    float getUniformValue();
    double getUniformValueDouble();

private:
   pcg32 m_rng;
   uint64_t m_sequenceIndex;
   uint64_t m_sequenceStartingPoint;

};


#endif
