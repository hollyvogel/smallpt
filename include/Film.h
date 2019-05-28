#ifndef FILM_H_
#define FILM_H_

#include <memory>
#include <Util.h>
#include <Sample.h>
#include <Data.h>

class Film
{

public:

    Film():  m_resolution(), res_x(0), res_y(0)  {;}

   unsigned int getRatio(Point2i _resolution);
   unsigned int ratio();

   void setResolution(Point2i _resolution);
   //void addColour(const unsigned int _posX, const unsigned int _posY, const Colour3f _colour);
   void addImage(const std::vector< std::vector< Colour3f >> &_image);
   void addSample(const int x_pos, const int y_pos, const Colour3f _sample);

   std::vector< std::vector<Colour3f>> getImage();

private:
    std::vector<std::vector<Colour3f >>m_image;

    std::vector< std::vector<Sample> > m_pixels;
    std::shared_ptr<Data> m_data;
    Point2i m_resolution;
    unsigned int res_x;
    unsigned int res_y;
    unsigned int m_ratio;

};

#endif

