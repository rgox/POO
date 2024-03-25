#ifndef CIRCLE_HPP
#define CIRCLE_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include "forme.hpp"
#include "point.hpp"

class Circle : public Forme {
public:
    Circle(const Point& c, float r) : center(c), radius(r) {} ;
    Circle(float x, float y, float r) : center(x, y), radius(r) {} ;
    
    const float& getX() const {return center.getX(); };
    const float& getY() const {return center.getY(); };
    const Point& getCenter() const  {return center; };
    const float& getRadius() const {return radius; };

    void display(Renderer& renderer) const;

private:
    Point center;
    float radius;

};


#endif // CIRCLE_HPP

