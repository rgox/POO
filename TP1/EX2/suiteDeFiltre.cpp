// SuiteDeFiltre.cpp
#include "suiteDeFiltre.hpp"

SuiteDeFiltre::SuiteDeFiltre() : Filtre("SuiteDeFiltre") {}

//ajoute un filtre dans le vecteur qui stocke la "liste" de filtre
void SuiteDeFiltre::add(Filtre* f) {
    filtres.push_back(f);
}

//Parcours le vecteur de filtre et utilise leur propre méthode apply pour l'appliquer sur l'image
void SuiteDeFiltre::apply(Image& i) const {
    for (Filtre* f : filtres) {//On parcours le vecteur de pointeurs vers des filtres
        if (f) { //Si le filtre n'est pas nul, on l'applique
            f->apply(i);
        }
    }
}

//destructeur
SuiteDeFiltre::~SuiteDeFiltre() {
    for (Filtre* f : filtres) {
        delete f;
    }
}
