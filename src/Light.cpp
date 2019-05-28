#include <Light.h>

void Light::setDirection( Vector3f _direction)
{
    _direction.normalized();
    m_direction = _direction;

}

