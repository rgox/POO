#ifndef FILTRE_MOYENNE_HPP
#define FILTRE_MOYENNE_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018


#include "filtre.hpp"


class FiltreMoyenne : public Filtre {
public:
	FiltreMoyenne(int filtersize);
	virtual void apply(Image& img) const;
protected:
	int size;
};

#endif // FILTRE_MOYENNE_HPP

