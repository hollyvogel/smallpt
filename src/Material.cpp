#include <Material.h>
#include <BRDF.h>

Material::Material(MaterialType _type, Colour3f _colour, Colour3f _emission)
{
    m_type = _type;
    m_colour = _colour;
    m_emission = _emission;
}

Colour3f Material::getColour() const
{
    return m_colour;
}

Colour3f Material::getEmission() const
{
   return m_emission;
}

MaterialType Material::getType() const
{
   return m_type;
}

void Material::setColour(const Colour3f &_colour)
{
m_colour = _colour;
}

void Material::setEmission (const Colour3f &_emission)
{
m_emission = _emission;
}

void Material::setType (const MaterialType &_type)
{
m_type = _type;

if (m_type == diffuse && m_material != 0)
{
    std::shared_ptr<BRDF> brdf(new BRDF);
    m_material = brdf;
}

}
