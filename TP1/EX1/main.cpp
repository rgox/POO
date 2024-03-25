#include "vecteur.hpp"
#include <iostream>
#include <vector>

int main() {
    // Création de quelques vecteurs
    Vecteur v1;
    Vecteur v2(4, 3);
	Vecteur v3(3, 4);
   
    // Affichage des vecteurs
	//V1
	std::cout << "V1 : " << std::endl;
	v1.affiche();

	//V2
	std::cout << "V2 : " << std::endl;
	v2.affiche();

	//V3
	std::cout << "V3 : " << std::endl;
	v3.affiche();

    // Calcul de la norme des vecteurs
	//V1
	std::cout << "Norme de V1 :\n " << v1.norme() << std::endl;
	;

	//V2
	std::cout << "Norme de V2 :\n " << v2.norme() << std::endl;

	//V3
	std::cout << "Norme de V3 :\n " << v3.norme() << std::endl;
    
    // Addition de vecteurs
    Vecteur *add = v3.addition(v2);
	std::cout << "\nAddition de V2 et V3:"<<std::endl;
	add->affiche();

	
    return 0;
}
