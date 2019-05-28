#pragma once

#ifndef SHAPEINTERFACE_H_
#define SHAPEINTERFACE_H

#include <Material.h>
#include <SurfaceInteraction.h>


class ShapeInterface
{
public:

    virtual ~ShapeInterface() {}

    virtual  SurfaceInteraction intersect(const Ray3f &_ray) const = 0;

   // virtual inline Vector3f position() const =0;
    virtual Vector3f getNormal(const Vector3f &p0) const = 0;
    virtual Vector3f getPosition()const = 0;

    virtual std::shared_ptr<Material> getMaterial() const =0;
    virtual void setMaterial(std::shared_ptr<Material> &_material) =0;

    std::shared_ptr<Material> m_material;

};

#endif
