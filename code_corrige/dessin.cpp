// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#include "dessin.hpp"


void Dessin::display(Renderer& renderer)
{
    for(const forme_ptr f : formes)
        f->display(renderer);

    renderer.waitForExit();
}

