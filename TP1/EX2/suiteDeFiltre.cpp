// SuiteDeFiltre.cpp
#include "suiteDeFiltre.hpp"

SuiteDeFiltre::SuiteDeFiltre() : Filtre("SuiteDeFiltre") {}

//ajoute un filtre dans le vecteur qui stocke la "liste" de filtre
void SuiteDeFiltre::add(Filtre* f) {
    filtres.push_back(f);
}

//Parcours le vecteur de filtre et utilise leur propre méthode apply pour l'appliquer sur l'image
void SuiteDeFiltre::apply(Image& i) const {
    for (Filtre* f : filtres) {
        if (f) {
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
