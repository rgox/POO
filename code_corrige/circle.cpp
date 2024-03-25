// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#include "circle.hpp"
#include "renderer.hpp"

void Circle::display(Renderer& renderer) const
{
    renderer.displayCircle(*this);
}

