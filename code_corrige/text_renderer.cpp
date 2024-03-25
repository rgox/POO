// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include "text_renderer.hpp"
#include <iostream>


void TextRenderer::displayCircle(const Circle& c)
{
    *stream << "Cercle de centre (" << c.getX() << ", " << c.getY() << ") et de rayon " << c.getRadius() << std::endl;
}


void TextRenderer::displayLine(const Line& l)
{
    *stream << "Ligne du point (" << l.getX1() << ", " << l.getY1() << ") au point (" << l.getX2() << ", " << l.getY2() << ")" << std::endl;
    
}

void TextRenderer::displayRectangle(const Rectangle& r)
{
    *stream << "Rectangle de centre (" << r.getX() << ", " << r.getY() << "), de largeur " << r.getWidth() << " et de hauteur " << r.getHeight() << std::endl;
}


void TextRenderer::waitForExit()
{
    std::cout << "Appuyez sur Entrée pour continuer..." << std::endl;
    std::cin.get();
}
