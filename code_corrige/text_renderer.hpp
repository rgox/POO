#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022


#include "renderer.hpp"
#include <iostream>


class TextRenderer : public Renderer {

public:
    TextRenderer(std::ostream& os) : stream(&os) {};
    TextRenderer() : TextRenderer(std::cout) {}; // If no stream is given, use std::cout
    ~TextRenderer() {};

    void waitForExit();

    // Display methods
    void displayCircle(const Circle& c);
    void displayLine(const Line& l);
    void displayRectangle(const Rectangle& r);

    std::ostream& getStream() {return *stream;} ;

protected:

    std::ostream* stream;

};

#endif // TEXT_RENDERER_HPP

