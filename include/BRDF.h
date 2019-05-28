#ifndef BRDF_H_
#define BRDF_H_

#include <Util.h>
#include <RandomNumberGen.h>
#include <MaterialInterface.h>

class BRDF: public MaterialInterface

{

public:
   float uniformHemispherePdf(){return M_INV_2_PI;}

   Ray3f calculateCosWeighted(const Vector3f &_position, const Vector3f &_normal, std::shared_ptr<RandomNumberGen> &_random) const;


};

#endif
