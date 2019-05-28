#ifndef SPHERE_H_
#define SPHERE_H_

#include <Util.h>
#include <memory>
#include <Scene.h>

class Sphere: public ShapeInterface
{

public:
    Sphere() : m_radius(1.f), m_center(0.f,0.f,0.f) {;}


  //  inline Vector3f position() const {return m_center;}
    inline float radius() const {return m_radius;}

    inline void setPosition(const Vector3f &_position)  {m_center = _position;}
    inline void setRadius(const float _radius)  {m_radius = _radius;}

    SurfaceInteraction intersect(const Ray3f &_ray) const;
    Vector3f getNormal(const Vector3f &p0) const {return (p0 - m_center).normalized();}
    Vector3f getPosition()const {return m_center;}

    std::shared_ptr<Material> getMaterial() const;
    void setMaterial(std::shared_ptr<Material> &_material);

private:
    double m_radius;
    Vector3f m_center;

};

#endif
