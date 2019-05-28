#pragma once

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <memory>

#include <Util.h>
#include <Light.h>
#include <Camera.h>
#include <ShapeInterface.h>
#include <Material.h>

class Scene {

public:
    inline void addObject(std::shared_ptr<ShapeInterface> _objects) {m_objects.push_back(_objects);}
    inline void addLight(std::shared_ptr<Light> _light) {m_lights.push_back(_light);}
    inline void addCamera(std::shared_ptr<Camera> _camera) {m_camera = _camera;}

    inline std::shared_ptr<ShapeInterface> getObject(int _index) const {return m_objects[_index];}
    inline std::shared_ptr<Light> getLight(int _index) const {return m_lights[_index];}
    inline std::shared_ptr<Camera> getCamera() const {return m_camera;}

    inline void addMaterial(std::shared_ptr<Material> _material) {m_materials.push_back(_material);}
    inline std::shared_ptr<Material> getMaterial(int _index) const {return m_materials[_index];}

    //SurfaceInteraction intersect(const Ray3f &ray) const;

    inline int countObjects() const {return m_objects.size();}
    inline int countMaterials()const {return m_materials.size();}
    inline int countLights()const {return m_lights.size();}

private:
    std::vector<std::shared_ptr<ShapeInterface>>m_objects;
    std::shared_ptr<Camera> m_camera;
    std::vector<std::shared_ptr<Material>> m_materials;
    std::vector< std::shared_ptr<Light> >m_lights;
};

#endif
