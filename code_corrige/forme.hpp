#ifndef FORME_HPP
#define FORME_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#include <memory>

class Renderer;

class Forme {

public:
    virtual void display(Renderer& renderer) const =0;
    virtual ~Forme() {};

};


typedef std::shared_ptr<Forme> forme_ptr;

#endif // FORME_HPP

