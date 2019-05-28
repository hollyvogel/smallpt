#include <Camera.h>
#include <Data.h>


Camera::Camera()
{
  m_origin = Vector3f(0.f, 0.f, 0.f);
  m_forward = Vector3f(0.f, 0.f, -1.f);
  m_up = Vector3f(0.f, 1.f, 0.f);
  m_right = Vector3f(1.f, 0.f, 0.f);
  m_ratio = 1.f;
  m_fov = 35;
}


Ray3f Camera::getCameraRay(const double _x_pos, const double _y_pos, std::shared_ptr<RandomNumberGen> _rand)
{

    double width= m_width;
    double height = m_height;

    //float fov = 51.52;
    float scale = tan(deg_to_rad(m_fov * 0.5));
    m_ratio = width / height;

    double x_rand = _rand->getUniformValueDouble() / width;
    double y_rand = _rand->getUniformValueDouble() / height;

    double x = (2 * (_x_pos + 0.5) / width - 1) * m_ratio * scale + x_rand;
    double y = (1 - 2 * (_y_pos + 0.5) /height) * scale + y_rand;


    Vector3f target = Vector3f(x,y,-1);
    direction(target);

   Vector2f origin_sample;
   origin_sample.x() = _rand->getUniformValue();
   origin_sample.y() = _rand->getUniformValue();
   Vector3f initial_position = (m_right * origin_sample.x()) + (m_up * origin_sample.y());

    Ray3f output;
    output.origin =  initial_position;;
    output.dir = (target - m_origin).normalized();

    return output;
}

void Camera::direction(const Vector3f &_directio)
{
    m_forward = _directio.normalized();
    m_right = Vector3f(0.f,1.f,0.f).cross(m_forward).normalized();
    m_up = m_forward.cross(m_right).normalized();
}

//select uniformly distributed point inside a unit circle

Vector2f rejectionSample(RandomNumberGen &_randomGen) const
{

    Vector2f out(0.f,0.f);
    bool sampleFound = false;

    while (sampleFound != true)
    {
        float p_x = _randomGen.getUniformValue() - 0.5f;
        float p_y = _randomGen.getUniformValue() - 0.5f;
        out = Vector2f(p_x, p_y);

        //if vector is inside disk
        if (out.norm() < 1.f)
        {
           sampleFound = true;
        }
    }

    return out;
}


