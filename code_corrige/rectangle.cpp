// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#include "rectangle.hpp"

#include "renderer.hpp"

void Rectangle::display(Renderer& renderer) const
{
    renderer.displayRectangle(*this);
}


bool Rectangle::intersects(const Rectangle& other) const
{
    // Do X ranges intersect ?
    float xdist; // This will be the distance between the right edge of the leftmost rectangle and the left edge of the rightmost rectangle
    if(getX() < other.getX()) // We are the leftmost rectangle
        xdist = (other.getX() - other.getWidth()/2) - (getX() + getWidth()/2);
    else // other is the leftmost rectangle
        xdist = (getX() - getWidth()/2) - (other.getX() + other.getWidth()/2);
    
    if(xdist > 0) // no overlap
        return false;
    
    // Do Y ranges intersect ?
    float ydist; // This will be the distance between the bottom edge of the topmost rectangle and the top edge of the bottommost rectangle
    if(getY() < other.getY()) // We are the bottom rectangle
        ydist = (other.getY() - other.getHeight()/2) - (getY() + getHeight()/2);
    else // other is the bottom rectangle
        ydist = (getY() - getHeight()/2) - (other.getY() + other.getHeight()/2);
    
    if(ydist > 0) // no overlap
        return false;
    else
        return true; // overlap on both coords
}
