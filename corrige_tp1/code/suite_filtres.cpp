// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018

#include "suite_filtres.hpp"


SuiteDeFiltres::SuiteDeFiltres()
{
  name = "Suite de filtres";
}

void SuiteDeFiltres::add(Filtre* f)
{
  filtres.push_back(f);
}

void SuiteDeFiltres::apply(Image& img) const
{
  for(auto it = filtres.begin(); it != filtres.end(); it++)
    (*it)->apply(img);
}

