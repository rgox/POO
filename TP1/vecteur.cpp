#include "vecteur.hpp"
#include <iostream>
#include <cmath>

// Afficher les coordonnées
void Vecteur::affiche() const {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

// Calculer la norme
float Vecteur::norme() const {
    return std::sqrt(x * x + y * y);
}

// Additionner avec un autre vecteur
Vecteur* Vecteur::addition(const Vecteur& v) const {
    return new Vecteur(x + v.x, y + v.y);
}
