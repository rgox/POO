// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include "sfml_renderer.hpp"
#include <iostream>

SFMLRenderer::SFMLRenderer()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Fenêtre SFML");
    window->clear(sf::Color::Black);
}

SFMLRenderer::~SFMLRenderer()
{
    delete window;
}

void SFMLRenderer::displayCircle(const Circle& c)
{
    sf::CircleShape circle(c.getRadius()); // Create circle
    circle.setPosition(c.getX() - c.getRadius(), c.getY() - c.getRadius()); //  We must convert the center position to the top left point position
    
    window->draw(circle);
}


void SFMLRenderer::displayLine(const Line& l)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(l.getX1(), l.getY1())),
        sf::Vertex(sf::Vector2f(l.getX2(), l.getY2()))
    };

    window->draw(line, 2, sf::Lines);
}

void SFMLRenderer::displayRectangle(const Rectangle& r)
{
    sf::RectangleShape rectangle(sf::Vector2f(r.getWidth(), r.getHeight()));
    rectangle.setPosition(r.getX() - r.getWidth()/2, r.getY() - r.getHeight()/2); // We must convert the center position to the top left point position
    
    window->draw(rectangle);
}


void SFMLRenderer::waitForExit()
{
    window->display();
    
    std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;
    
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}
