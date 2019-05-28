#ifndef SURFACEINTERACTION_H_
#define SURFACEINTERACTION_H_

#include <Util.h>
#include <Material.h>

struct SurfaceInteraction
{
    SurfaceInteraction() : distance(0), hit(false), normal(Vector3f()), material(nullptr) {;}

    SurfaceInteraction(double _distance, bool _hit, Vector3f _normal, std::shared_ptr<Material> _material)
       {
           distance = _distance;
           hit = _hit;
           normal = _normal;
           material = _material;
       }

    operator bool() {return material != nullptr;}

    double distance;
    bool hit;
    Vector3f normal;
    std::shared_ptr<Material> material;

};

#endif
