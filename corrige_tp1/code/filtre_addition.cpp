// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018

#include "filtre_addition.hpp"
#include <sstream> 


FiltreAddition::FiltreAddition(int val)
{
  valeur = val;
  std::stringstream ssname;
  ssname << "Filtre addition valeur " << valeur;
  name = ssname.str();
}


void FiltreAddition::apply(Image& img) const
{
  // Iterate over image
  for(int i = 0; i < img.get_w(); i ++)
  {
    for(int j = 0; j < img.get_h(); j ++)
    {
      int v = img(i,j) + valeur; // put in an int to avoid weird overflow effects...
      if(v < 0) // ...and then check bounds
        img(i,j) = 0;
      else if(v > 255)
        img(i,j) = 255;
      else
        img(i,j) = (unsigned char)v;
    }
  }
}

/*
int main(int argc, char**argvs)
{
  Image im("cairo.pgm");
  //im.print();
  FiltreAddition f(-50);
  f.apply(im);
  im.write("test.pgm");
  return 0;
}*/
