#include <Film.h>
#include <Data.h>
#include <lodepng.h>

unsigned int Film::getRatio(Point2i _resolution)
{

    m_resolution[0]= _resolution[0];
    m_resolution[1]= _resolution[1];
    m_ratio = m_resolution[0]/m_resolution[1];

    return m_ratio;

}

unsigned int Film::ratio()
{

   return m_ratio;

}


void Film::setResolution(Point2i _resolution)
{
    m_resolution[0] = _resolution[0];
    m_resolution[1] = _resolution[1];

    //resize the container before using it
   m_pixels.clear();
   m_pixels.resize(m_resolution[0]);

  for (int column = 0; column < m_resolution[0]; ++column)
  {
    m_pixels[column].resize(m_resolution[1]);
  }

}


void Film::addSample(const int x_pos, const int y_pos, const Colour3f _sample)
{
m_pixels[x_pos][y_pos].addSample(_sample);
}

void Film::addImage(const std::vector< std::vector< Colour3f >> &_image)
{
    m_image.clear();
    m_image.resize(m_resolution[0]);

   for (int col = 0; col < m_resolution[0]; ++col)
   {
     m_image[col].resize(m_resolution[1]);
   }

m_image = _image;


std::vector<unsigned char> imagePNG(m_resolution[0] * m_resolution[1] * 4);
//image.resize(width * height * 4);

for (int i = 0; i < m_resolution[0]; ++i) //rows
{

  for (int j = 0; j <  m_resolution[1]; ++j) //cols
  {
   /*
    imagePNG[4 * m_resolution[0] * i + 4 * j + 0] = static_cast<unsigned char>(std::floor(m_image[j][i].x() * 255.f));
    imagePNG[4 * m_resolution[0] * i + 4 * j + 1] = static_cast<unsigned char>(std::floor(m_image[j][i].y() * 255.f));
    imagePNG[4 * m_resolution[0] * i + 4 * j + 2] = static_cast<unsigned char>(std::floor(m_image[j][i].z() * 255.f));
    imagePNG[4 * m_resolution[0] * i + 4 * j + 3] = 255;
 */

      imagePNG[4 * m_resolution[0] * i + 4 * j + 0] = static_cast<unsigned char> (m_image[j][i].x());
      imagePNG[4 * m_resolution[0] * i + 4 * j + 1] = static_cast<unsigned char> (m_image[j][i].y());
      imagePNG[4 * m_resolution[0] * i + 4 * j + 2] = static_cast<unsigned char> (m_image[j][i].z());
      imagePNG[4 * m_resolution[0] * i + 4 * j + 3] = 255;

//      m_image[j][i].x() = m_image[m_resolution[1] - j - 1][i].x();
//      m_image[j][i].y() = m_image[m_resolution[1] - j - 1][i].y();
//      m_image[j][i].z() = m_image[m_resolution[1] - j - 1][i].z();

}
}

const char* filename = "ORINOCO.png";

lodepng::encode(filename, imagePNG, m_resolution[0], m_resolution[1]);

}






