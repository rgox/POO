#include "filtre.hpp"
#include "image.hpp"

//Constructeur pour la classe filtre 
Filtre::Filtre(const std::string& name) : name(name) {} 

//Méthode pour récuperer le nom du filtre
const std::string& Filtre::get_name() const {
    return name;
}

//destructeur
Filtre::~Filtre() {}
