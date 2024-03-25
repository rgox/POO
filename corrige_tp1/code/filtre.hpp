#ifndef FILTRE_HPP
#define FILTRE_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018

#include "image.hpp"
#include <string>

class Filtre {
public:
	virtual void apply(Image& img) const =0;
	virtual const std::string& get_name() {return name;};
protected:
	std::string name;
};


#endif // FILTRE_HPP

