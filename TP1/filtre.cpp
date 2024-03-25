#include "filtre.hpp"
#include "image.hpp"

Filtre::Filtre(const std::string& name) : name(name) {}

const std::string& Filtre::get_name() const {
    return name;
}

Filtre::~Filtre() {}
