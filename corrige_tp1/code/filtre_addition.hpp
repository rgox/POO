#ifndef FILTRE_ADDITION_HPP
#define FILTRE_ADDITION_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018


#include "filtre.hpp"


class FiltreAddition : public Filtre {
public:
	FiltreAddition(int val);
	virtual void apply(Image& img) const;
protected:
	int valeur;
};

#endif // FILTRE_ADDITION_HPP

