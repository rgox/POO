#ifndef LINE_HPP
#define LINE_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include "forme.hpp"
#include "point.hpp"

class Line : public Forme {
public:
    Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {} ;
    Line(float x1, float y1, float x2, float y2) : p1(x1,y1),  p2(x2,y2) {} ;
    
    const float& getX1() const {return p1.getX(); };
    const float& getY1() const {return p1.getY(); };
    const Point& getP1() const  {return p1; };
    
    const float& getX2() const {return p2.getX(); };
    const float& getY2() const {return p2.getY(); };
    const Point& getP2() const  {return p2; };


    void display(Renderer& renderer) const;

private:
    Point p1;
    Point p2;

};

#endif
