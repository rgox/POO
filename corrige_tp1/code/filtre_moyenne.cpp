// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018

#include "filtre_moyenne.hpp"
#include <sstream> 


FiltreMoyenne::FiltreMoyenne(int filtersize)
{
  size = filtersize;
  if(size <= 0)
    throw(std::invalid_argument("Mean filter must have size > 0"));
  std::stringstream ssname;
  ssname << "Filtre moyenne " << size << "x" <<size;
  name = ssname.str();
}


void FiltreMoyenne::apply(Image& img) const
{
  int new_w = img.get_w() - size + 1;
  int new_h = img.get_h() - size + 1;
  if(new_w <= 0 || new_h <= 0)
    throw(std::domain_error("Image too small for filter size"));

  /* We can't just iterate over the pixels and update them 
     in place, since the value of each pixel would be affected
     by its previously processed neighbors.
     We must build a new image and then replace img with it. */

  Image newimg(new_w, new_h); // new image of the final size
  
  // Outer loop (image pixels)
  for(int i = 0; i < new_w; i ++)
  {
    for(int j = 0; j < new_h; j ++)
    {
      // Inner loop (filter)
      int filterout = 0;
      for(int ii = i; ii < i+size ; ii++)
      {
        for(int jj = j; jj < j+size ; jj++)
        {
          filterout += img(ii,jj);
        }
      }
      filterout /= size*size; // average
      if(filterout < 0) // should not occur but better to check
        newimg(i,j) = 0;
      else if(filterout > 255)
        newimg(i,j) = 255;
      else
        newimg(i,j) = (unsigned char)filterout;
    }
  }
  img = newimg; // replace original image with the averaged one
}

/*
int main(int argc, char**argvs)
{
  Image im("cairo.pgm");
  //im.print();
  FiltreMoyenne f(3);
  f.apply(im);
  im.write("test.pgm");
  return 0;
}*/
