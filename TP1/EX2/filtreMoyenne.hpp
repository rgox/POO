#ifndef FILTREMOYENNE_HPP
#define FILTREMOYENNE_HPP

#include "filtre.hpp"
#include "image.hpp" 

class FiltreMoyenne : public Filtre {
private:
    int taille; // Taille de la zone carrée pour la moyenne

public:
    // Constructeur
    FiltreMoyenne(int taille);

    // Méthode pour appliquer le filtre sur l'image
    void apply(Image& i) const override;
};

#endif // FILTREMOYENNE_HPP
