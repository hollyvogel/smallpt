#ifndef PATHINTEGRATOR_H_
#define PATHINTEGRATOR_H_

#include <Scene.h>
#include <RandomNumberGen.h>

class PathIntegrator
{
public:
    PathIntegrator() : m_currentDepth(0), m_maxDepth(5) {;}

    Colour3f trace(const Ray3f _sample,const std::shared_ptr<Scene> _scene, const Colour3f _colourContribution, std::shared_ptr<RandomNumberGen> _randGen);

private:
    int m_currentDepth;
    int m_maxDepth;

 };


#endif

