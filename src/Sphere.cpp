#include <Sphere.h>
#include <cmath>

SurfaceInteraction Sphere::intersect(const Ray3f &_ray) const
{

Vector3f distance_op = m_center -_ray.origin;

bool hit = false;
double distance = 0;
Vector3f normal = Vector3f();

double t;
double  B_term = distance_op.dot(_ray.dir);
double det = B_term * B_term - distance_op.dot(distance_op) + m_radius * m_radius;

if (det < 0)
{
    return SurfaceInteraction(distance, hit, normal, m_material);
}
else
{
    det = sqrt(det);
}

distance = (t = B_term - det) > M_EPSILON ? t : ((t = B_term + det) > M_EPSILON ? t : 0 );

if (distance != 0)
{
    hit = true;
    normal = ((_ray.origin + _ray.dir * distance) - m_center);
    normal.normalized();
}


return SurfaceInteraction(distance, hit, normal, m_material);


}


std::shared_ptr<Material> Sphere::getMaterial() const
{
    return m_material;
}


void Sphere::setMaterial(std::shared_ptr<Material> &_material)
{
    m_material = _material;
}

