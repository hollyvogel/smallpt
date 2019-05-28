#ifndef DATA_H_
#define DATA_H_

struct Data
{
Data():
    res_x(700),
    res_y(700),
    samplesPerPixel(50)
{;}

 int res_x;
 int res_y;
 int bounces;
 const double samplesPerPixel;

};

#endif
