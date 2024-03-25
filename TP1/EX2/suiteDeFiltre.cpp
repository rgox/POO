// SuiteDeFiltre.cpp
#include "suiteDeFiltre.hpp"

SuiteDeFiltre::SuiteDeFiltre() : Filtre("SuiteDeFiltre") {}

void SuiteDeFiltre::add(Filtre* f) {
    filtres.push_back(f);
}

void SuiteDeFiltre::apply(Image& i) const {
    for (Filtre* f : filtres) {
        if (f) {
            f->apply(i);
        }
    }
}

SuiteDeFiltre::~SuiteDeFiltre() {
    for (Filtre* f : filtres) {
        delete f;
    }
}
