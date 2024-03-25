#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include <SFML/Graphics.hpp>

#include "renderer.hpp"

class SFMLRenderer : public Renderer {

public:
    SFMLRenderer();
    ~SFMLRenderer();
    

    // Display methods
    void displayCircle(const Circle& c);
    void displayLine(const Line& l);
    void displayRectangle(const Rectangle& r);


    void waitForExit();
    
    sf::RenderWindow& getWindow() {return *window;};

private:
     sf::RenderWindow* window;
};

#endif // SFML_RENDERER_HPP

