#ifndef SAMPLE_H_
#define SAMPLE_H_

#include <memory>
#include <Util.h>
#include <vector>
#include <Data.h>


class Sample
{
public:

    Colour3f averageSample() const;
    void addSample(const Colour3f _sample);
    Colour3f getSample(int _index)const;

private:
    std::shared_ptr<Data> m_data;
    std::vector<Colour3f>m_samples;
    Colour3f m_sample;
};

#endif
