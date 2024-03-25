// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018

#include "image.hpp"
#include "filtre_moyenne.hpp"
#include "filtre_addition.hpp"
#include "suite_filtres.hpp"


int main(int argc, char**argvs)
{
  Image im("cairo.pgm");
  //im.print();
  FiltreAddition fplus(50);
  FiltreAddition fminus(-50);
  FiltreMoyenne m(5);
  SuiteDeFiltres sdf, sdf2;
  sdf.add(&fplus);
  sdf.add(&m);
  sdf2.add(&fminus);
  sdf2.add(&m);
  Image im2(im);
  sdf.apply(im);
  sdf2.apply(im2);
  Image im3 = im - im2;
  im3.write("test.pgm");
  return 0;
}
