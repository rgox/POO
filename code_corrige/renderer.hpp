#ifndef RENDERER_HPP
#define RENDERER_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022


// Forward declarations to avoid circular includes

#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"

class Renderer {
public:
    virtual void waitForExit() =0;

    // Display methods
    virtual void displayCircle(const Circle& c) =0;
    virtual void displayLine(const Line& l) =0;
    virtual void displayRectangle(const Rectangle& r) =0;
};


#endif // RENDERER_HPP

