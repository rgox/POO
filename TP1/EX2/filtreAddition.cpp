#include "filtreAddition.hpp"

FiltreAddition::FiltreAddition(int valeur) : Filtre("Addition"), valeur(valeur) {}


//Méthode pour appliquer le filtre 
//Ce filtre parcours tout les pixel de l'image et ajoute une valeur passée en paramètre
void FiltreAddition::apply(Image& i) const {
    for (size_t y = 0; y < i.get_w(); ++y) {
        for (size_t x = 0; x < i.get_h(); ++x) {
            int newValue = i.get(x, y) + valeur; //On ajoute la valeur souhaitée
            if (newValue < 0) newValue = 0; //vérification que l'on ne créer pas un pixel négatif
            if (newValue > 255) newValue = 255; //ni supérieur à 255
            i.set(x, y, newValue);
        }
    }
}