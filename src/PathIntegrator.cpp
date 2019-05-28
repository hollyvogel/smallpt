#include <PathIntegrator.h>
#include <Scene.h>


Colour3f PathIntegrator::trace(const Ray3f _ray,const std::shared_ptr<Scene> _scene, std::shared_ptr<RandomNumberGen> _random, const Colour3f _colourContribution)

{

    SurfaceInteraction intersection = _scene->intersect(_ray);

    //const std::shared_ptr<ShapeInterface> &object = _scene->getObject(id);
    Ray3f ray_reflected;

    // TRANSMISSION HERE

    if (!intersection)
    {
    return Colour3f(255.f,255.f,255.f);
    }

    Colour3f brdf_modulator = intersection.material->getColour();

    float max_reflection = brdf_modulator.x() > brdf_modulator.y()  && brdf_modulator.x() > brdf_modulator.z() ? brdf_modulator.x() : brdf_modulator.y() > brdf_modulator.z() ? brdf_modulator.y() : brdf_modulator.z();

        if (++m_currentDepth > m_maxDepth)
        {
            if(_random->getUniformValueDouble() < max_reflection)
            {
            brdf_modulator = brdf_modulator * (1/max_reflection);
            }
            else
            {
            return intersection.material->getEmission();
            }
        }


        Vector3f normal = intersection.normal.normalized(), position = _ray.origin + _ray.dir * intersection.distance;

        // oriented normal
        Vector3f Normal = normal.dot(_ray.dir) < 0 ? normal : normal * -1;

        float normX = static_cast<float>(Normal[0]);
        float normY = static_cast<float>(Normal[1]);
        float normZ = static_cast<float>(Normal[2]);

        Normal[0] = std::max(normX,0.1f);
        Normal[1] = std::max(normY,0.1f);
        Normal[2] = std::max(normZ,0.1f);

        ray_reflected = intersection.material->returnMaterial()->calculateCosWeighted(position, Normal,_random);

//        ray_reflected.origin = position;
//        ray_reflected.dir = intersection.material->returnMaterial()->uniformSampleHemisphere(orntdNormal, _random);
        Colour3f colour = intersection.material->getColour();

  //      Colour3f colour = intersection.material->getColour();

return trace(ray_reflected, _scene, _random, _colourContribution);
//return colour;

}


