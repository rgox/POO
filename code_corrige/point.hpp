#ifndef POINT_HPP
#define POINT_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

class Point {
public:
    Point(float x, float y): x(x), y(y) {} ;
    //Point(): Point(0., 0.) {} ;
    const float& getX() const {return x; };
    const float& getY() const {return y; };

private:
    float x;
    float y;

};

#endif // POINT_HPP

