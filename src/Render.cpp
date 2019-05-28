#include <Render.h>
#include <PathIntegrator.h>
#include <lodepng.h>
#include <HaltonSampler.h>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>



void Render::getScene( std::shared_ptr<Scene> _scene_data)
{
    m_scene_data = _scene_data;
}

void Render::getOptions(std::shared_ptr<Data> _options)
{
    m_data = _options;
}



void Render::render()
{

int imageWidth = m_data->res_x;
int imageHeight = m_data->res_y;
const  double spp = m_data->samplesPerPixel;

Film myImage;
Point2i resolution(imageWidth, imageHeight);
myImage.setResolution(resolution);


std::shared_ptr<RandomNumberGen>randomNumber(new RandomNumberGen());
//seed
uint64_t seed_i = randomNumber->getSeed();
uint64_t seed_s = randomNumber->getSeed();

randomNumber->setIndex(seed_i);
randomNumber->setSequenceStartingPoint(seed_s);

std::shared_ptr<PathIntegrator> pathtracer(new PathIntegrator());


std::vector<std::vector<Sample>> samples;
//set size before use
    samples.resize(imageWidth);
    for (int x_pos = 0; x_pos < imageWidth; ++x_pos)
    {
      samples[x_pos].resize(imageHeight);
    }


 std::shared_ptr<Camera> camera;

camera = m_scene_data->getCamera();


for(int materials =0; materials < m_scene_data->countMaterials(); ++materials)
{
 m_scene_data->getMaterial(materials);
}



#pragma omp parallel for schedule(dynamic,1)

//for(int x_pos = 0; x_pos < imageWidth; ++x_pos)
//{
//    fprintf(stdout,"\rRendering: %1.0fspp %8.2f%%",spp,(double)x_pos/imageWidth*100);

//    for(int y_pos =0; y_pos < imageHeight; ++y_pos)
//    {


//        for (int sy=0, i=(imageHeight-y_pos-1) * imageWidth + x_pos; sy<2; sy++)     // 2x2 subpixel rows

//          for (int sx=0; sx<2; sx++)
//          {        // 2x2 subpixel cols


//                for(int sample = 0; sample < spp; ++sample )
//                {
//                double rand1 = randomNumber->getUniformValueDouble();
//                double rand2 = randomNumber->getUniformValueDouble();

//                Vector3f jitter = camera->subSample(x_pos,y_pos,sx,sy,rand1,rand2);

//                //camera->setOrigin(jitter);

//                Ray3f ray = camera->ray(x_pos, y_pos);
//                //ray.origin = jitter;

//                Colour3f collectLight = pathtracer->trace(ray, m_scene_data,randomNumber);

//                //radiance += radiance/spp;
//                samples[x_pos][y_pos].addSample(collectLight);
//                }
//          }
//    }
//}

    for(int x_pos = 0; x_pos < imageWidth; ++x_pos)
    {
        fprintf(stdout,"\rRendering: %1.0fspp %8.2f%%",spp,(double)x_pos/imageWidth*100);

        for(int y_pos =0; y_pos < imageHeight; ++y_pos)
        {
            for(int sample = 0; sample < spp; ++sample )
            {
//            double x_rand_offset = 0;
//            double y_rand_offset = 0;

            camera->setOrigin(Vector3f(0.f,0.f,0.f));

            Ray3f ray = camera->getCameraRay(x_pos, y_pos, randomNumber);

            Colour3f collectLight = pathtracer->trace(ray, m_scene_data,randomNumber);

            //radiance += radiance/spp;
            samples[x_pos][y_pos].addSample(collectLight);

            }



        }
    }




std::vector< std::vector<Colour3f>> toColour;

  for (int x_pos =0; x_pos< imageWidth; x_pos++)
  {
    std::vector<Colour3f> col;
    for (int y_pos=0; y_pos < imageHeight; y_pos++)
    {
     Colour3f colour;
     colour = samples[x_pos][y_pos].averageSample();

     col.push_back(colour);
    }
    toColour.push_back(col);
  }

samples.clear();
myImage.addImage(toColour);

toColour.clear();

}






/*
void Render::exportImage()

{
    std::vector<std::vector<Vector3f>> imageOut;
    imageOut = m_image->getImage();

    std::vector<unsigned char> image();

}


*/
