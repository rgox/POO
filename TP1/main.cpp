#include "vecteur.hpp"
#include "image.hpp"
#include "filtreAddition.hpp"
#include "suiteDeFiltre.hpp"
#include "filtreMoyenne.hpp"
#include <iostream>

int main() {

	/*
    Vecteur v1, v2(1, 2);
    v1.affiche();  // Afficher v1
	v2.affiche();
    std::cout << "Norme de v2: " << v2.norme() << std::endl;  // Norme de v1

    Vecteur* v3 = v1.addition(v2);  // Additionner v1 et v2
    v3->affiche();  // Afficher le résultat de l'addition
    delete v3;  // Libérer la mémoire
	*/
	// Charger une image
	// Charger une image
    Image img("cairo.pgm");
    // Tester le constructeur par copie
    Image imgCopy = img;

    // Obtenir les dimensions de l'image
    size_t width = img.get_w();
    size_t height = img.get_h();
    std::cout << "Dimensions de l'image : " << width << " x " << height << std::endl;

    // Modifier quelques pixels
    for (size_t i = height/2-50; i < height/2+50; ++i) {
        for (size_t j = width/2-50; j < width/2+50; ++j) {
            img.set(i, j, 159); // Définir en blanc
        }
    }

    // Obtenir la valeur d'un pixel spécifique
    unsigned char pixelValue = img.get(5, 5);
    std::cout << "Valeur du pixel (5,5) : " << static_cast<int>(pixelValue) << std::endl;

    // Sauvegarder l'image modifiée
    img.write("cairo2.pgm");

    std::cout << "L'image a été modifiée et enregistrée avec succès." << std::endl;

	// Appliquer le filtre Addition
    FiltreAddition filtre(90);  // Créer un filtre qui ajoute 30 à chaque pixel
    Image imgFiltree = imgCopy;     // Créer une copie de l'image pour appliquer le filtre
    filtre.apply(imgFiltree);   // Appliquer le filtre

	pixelValue = imgFiltree.get(5, 5);
	std::cout << "Valeur du pixel après filtrage (5,5) : " << static_cast<int>(pixelValue) << std::endl;

    // Sauvegarder l'image filtrée
    imgFiltree.write("cairo_filtréeAddition.pgm");

    std::cout << "L'image filtrée a été enregistrée avec succès." << std::endl;

	// Appliquer le filtre Moyenne
    FiltreMoyenne filtre2(1); 
    Image imgFiltree2 = imgCopy;     // Créer une copie de l'image pour appliquer le filtre
    filtre2.apply(imgFiltree2);   // Appliquer le filtre

	pixelValue = imgFiltree2.get(5, 5);
	std::cout << "Valeur du pixel après filtrage (5,5) : " << static_cast<int>(pixelValue) << std::endl;

    // Sauvegarder l'image filtrée
    imgFiltree2.write("cairo_filtréeMoyenne.pgm");

    std::cout << "L'image filtrée a été enregistrée avec succès." << std::endl;


	Image imgFiltree3 = imgCopy;

	// Créer la suite de filtres
    SuiteDeFiltre suite;

    // Ajouter des filtres à la suite
    suite.add(new FiltreAddition(30));  // Ajouter un filtre d'addition
    suite.add(new FiltreMoyenne(1));    // Ajouter un filtre moyenne

    // Appliquer la suite de filtres sur l'image
    suite.apply(imgFiltree3);

    // Sauvegarder l'image résultante
    imgFiltree3.write("cairo_filtréeSuite.pgm");

    std::cout << "L'image après application de la suite de filtres a été enregistrée avec succès." << std::endl;

    // Le destructeur sera appelé automatiquement
    return 0;
}
