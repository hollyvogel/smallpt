#ifndef CAMERA_H_
#define CAMERA_H_

#include <Util.h>
#include <RandomNumberGen.h>

class Camera
{

public:
    Camera();

        inline Vector3f getOrigin() const {return m_origin;}
        inline Vector3f getDirection() const {return m_forward;}
        inline Vector3f getCamRight() const {return m_right;}
        inline float getRatio() const {return m_ratio;}
        inline float getWidth() const {return m_width;}
        inline float getHeight() const {return m_height;}

        void direction(const Vector3f &_directio);

        inline void setOrigin(const Vector3f &_origin) {m_origin = _origin;}
        inline void setRatio(const float &_ratio){m_ratio = _ratio;}

        inline void setWidth(const float &_width){m_width = _width;}
        inline void setHeight(const float &_height){m_height = _height;}

        inline float deg_to_rad(const float _degrees) { return _degrees * M_PI / 180; }

        Ray3f getCameraRay(const double _x_pos, const double _y_pos, std::shared_ptr<RandomNumberGen> _rand);

private:

    Vector2f rejectionSample(RandomNumberGen &_randomGen) const;
    Vector3f m_origin;
    Vector3f m_forward;
    Vector3f m_right;
    Vector3f m_up;
    double m_width;
    double m_height;
    float m_ratio;
    float m_fov;

    float m_aperture;
    float m_focal_distance;

};

#endif
