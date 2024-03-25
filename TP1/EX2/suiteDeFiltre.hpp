// SuiteDeFiltre.hpp
#ifndef SUITEDEFILTRE_HPP
#define SUITEDEFILTRE_HPP

#include "filtre.hpp"
#include <vector>

class SuiteDeFiltre : public Filtre {
private:
    std::vector<Filtre*> filtres; // Vecteur de pointeurs vers des objets Filtre

public:
    // Constructeur
    SuiteDeFiltre();

    // Méthode pour ajouter un filtre à la suite
    void add(Filtre* f);

    // Méthode pour appliquer tous les filtres de la suite sur l'image
    void apply(Image& i) const override;

    // Destructeur
    ~SuiteDeFiltre();
};

#endif // SUITEDEFILTRE_HPP
