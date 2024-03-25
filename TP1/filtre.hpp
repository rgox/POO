#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <string>

class Image; // Déclaration anticipée

class Filtre {
protected:
    std::string name; // Nom du filtre

public:
    // Constructeur
    Filtre(const std::string& name);

    // Méthode abstraite apply
    virtual void apply(Image& i) const = 0;

    // Méthode pour obtenir le nom du filtre
    const std::string& get_name() const;

    // Destructeur virtuel
    virtual ~Filtre();
};

#endif // FILTRE_HPP
