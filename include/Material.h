#pragma once
#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <Util.h>

enum MaterialType { diffuse, specular , emission };

class Material
{

friend class BRDF;

public:

    Material(MaterialType _type, Colour3f _colour, Colour3f _emission);

    void setColour(const Colour3f &_colour);
    void setEmission (const Colour3f &_emission);
    void setType (const MaterialType &_type);
    Colour3f getColour()const;
    Colour3f getEmission()const;
    MaterialType getType()const;

private:

    Colour3f m_colour;
    Colour3f m_emission;
    MaterialType m_type;

};

#endif
