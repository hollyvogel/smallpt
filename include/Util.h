#ifndef _UTIL_H_
  #define _UTIL_H_

  #include <cfloat>
  #include <cmath>

  #include <lib/Eigen/Core>
  #include <lib/Eigen/StdVector>
  #include <lib/Eigen/Geometry>

  #ifdef M_PI
    #undef M_PI
  #endif

  #define M_PI 3.14159265358979323846f
  #define M_INV_PI 0.31830988618379067154f
  #define M_INV_2_PI 0.15915494309189533576f
  #define M_PI_180 0.01745329251994329577f
  #define M_180_PI 57.2957795130823208768f
  #define M_EPSILON FLT_EPSILON
  #define M_INFINITY FLT_MAX

//  template < typename t_origin, typename t_direction > struct Ray
//  {
//    t_origin origin;
//    t_direction dir;
//  };


  typedef Eigen::Matrix< float, 2, 1 > Vector2f;
  typedef Eigen::Matrix< float, 3, 1 > Vector3f;

  typedef Eigen::Matrix< float, 4, 4 > TransMatrix;
  typedef Ray< Vector3f, Vector3f > Ray3f;
  typedef Eigen::Array< float, 3, 1 > Colour3f;

  typedef Eigen::Matrix<int ,2,1> Point2i;
  typedef Eigen::Matrix<float,2,1> Point2f;

#endif
