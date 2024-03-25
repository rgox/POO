#include "filtreAddition.hpp"

FiltreAddition::FiltreAddition(int valeur) : Filtre("Addition"), valeur(valeur) {}

void FiltreAddition::apply(Image& i) const {
    for (size_t y = 0; y < i.get_w(); ++y) {
        for (size_t x = 0; x < i.get_h(); ++x) {
            int newValue = i.get(x, y) + valeur;
            if (newValue < 0) newValue = 0;
            if (newValue > 255) newValue = 255;
            i.set(x, y, newValue);
        }
    }
}