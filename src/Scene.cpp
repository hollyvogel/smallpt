#include <Scene.h>

 SurfaceInteraction Scene::intersect(const Ray3f &ray) const
 {
    SurfaceInteraction intersection = SurfaceInteraction();
    SurfaceInteraction temp;
    long numOfObjects = countObjects();

    for (int i = 0; i < numOfObjects; ++i)
    {
        temp = m_objects.at((unsigned)i)->intersect(ray);

        if (temp.hit)
        {
            if (intersection.distance == 0 || temp.distance < intersection.distance)
            {
                intersection = temp;
            }
        }
    }
return intersection;
}



