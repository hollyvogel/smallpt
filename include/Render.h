#ifndef RENDER_H_
#define RENDER_H_

#include <memory>
#include <Scene.h>
#include <Film.h>
#include <Data.h>
#include <SamplerAbstract.h>

class Render
{
public:


    void getScene( std::shared_ptr<Scene> _scene_data);
    void getOptions(std::shared_ptr<Data> _options);
    void render();
    void exportImage();


private:

    int m_depthCounter;
    int m_maxDepth;
    std::shared_ptr<Scene> m_scene_data;
   // std::shared_ptr<Film> m_image;
    std::shared_ptr<Data> m_data;

    std::shared_ptr<SamplerAbstract>m_tracer;
};

#endif
