#include <BRDF.h>
#include <cmath>


Ray3f BRDF::calculateCosWeighted(const Vector3f &_position, const Vector3f &_normal, std::shared_ptr<RandomNumberGen> &_random) const
{
    Ray3f brdf;
    Vector3f u,v;

    double r1=2*M_PI*_random->getUniformValue(), r2=_random->getUniformValue(), r2s=sqrt(r2);

if(_normal[2] < -0.9999999f)
{
u = Vector3f(0.0, -1.0, 0.0);
v = Vector3f(-1.0, 0.0, 0.0);
}
const double a = 0.1/(0.1 + _normal[2]);
const double b = -_normal[0] * _normal[1] * a;

u = Vector3f(1.0 - _normal[0] * _normal[0] * a, b, -_normal[0]);
v = Vector3f(b, 1.0 - _normal[1] * _normal[1] * a, -_normal[1]);
Vector3f w=_normal;

Vector3f d = (u*cos(r1)*r2s + v*sin(r1)*r2s + w*sqrt(1-r2));
d.normalized();

brdf.origin = _position;
brdf.dir = d;

return brdf;

}
