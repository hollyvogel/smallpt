#ifndef LIGHT_H_
#define LIGHT_H_

#include <Util.h>

class Light
{
public:
    Light() : m_origin(0.f,0.f,0.f), m_direction(0.f,0.f,0.f) {;}

    inline Vector3f getOrigin() const {return m_origin;}
    inline Vector3f getDirection() const {return m_direction;}

    inline void setOrigin(const Vector3f _origin){m_origin = _origin;}

    void setDirection(Vector3f _direction);

private:
    Vector3f m_origin;
    Vector3f m_direction;

};

#endif
