#ifndef SUITE_FILTRES_HPP
#define SUITE_FILTRES_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 09/04/2018


#include "filtre.hpp"
#include <vector>

class SuiteDeFiltres : public Filtre {
public:
	SuiteDeFiltres();
	virtual void apply(Image& img) const;
	void add(Filtre* f);
protected:
	std::vector<Filtre*> filtres;
};

#endif // SUITE_FILTRES_HPP

