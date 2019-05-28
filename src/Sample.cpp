#include <Sample.h>


void Sample::addSample(const Colour3f _sample)
{
 m_samples.push_back(_sample);
}


Colour3f Sample::averageSample() const
{
//unsigned int sampleTotal = (m_data->samplesPerPixel);

int numberOfSamples = m_samples.size();

Colour3f sampleSum(0.f,0.f,0.f);

if (numberOfSamples != 0)
{

for(int sample =0; sample < numberOfSamples; ++sample)
{
 sampleSum += m_samples[sample];
}
}
else
{
numberOfSamples = 1;
}

return sampleSum/numberOfSamples;
}

Colour3f Sample::getSample(int _index)const
{
return m_samples[_index];
}
