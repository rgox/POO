#ifndef FILTREADDITION_HPP
#define FILTREADDITION_HPP

#include "filtre.hpp"
#include "image.hpp"
class FiltreAddition : public Filtre {
private:
    int valeur; // La valeur à ajouter aux pixels

public:
    // Constructeur
    FiltreAddition(int valeur);

    // Méthode pour appliquer le filtre sur l'image
    void apply(Image& i) const override;
};

#endif // FILTREADDITION_HPP