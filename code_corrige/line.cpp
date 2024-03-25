// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#include "line.hpp"
#include "renderer.hpp"


void Line::display(Renderer& renderer) const
{
    renderer.displayLine(*this);
}
