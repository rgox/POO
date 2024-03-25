#ifndef DESSIN_HPP
#define DESSIN_HPP
// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022


#include "forme.hpp"
#include "renderer.hpp"
#include <vector> // std::vector
#include <cstddef> // size_t

class Dessin {
public:
    void addForme(forme_ptr forme) { formes.push_back(forme); }; // Add shape by reference...

    void display(Renderer& renderer);
    
    forme_ptr getForme(std::size_t i) {return formes[i];}; // will throw std::out_of_range on wrong index
    
    std::size_t nFormes() const {return formes.size();}

protected:
    std::vector<forme_ptr> formes;
};

#endif // DESSIN_HPP

