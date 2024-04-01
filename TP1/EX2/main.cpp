#include "image.hpp"
#include "filtreAddition.hpp"
#include "suiteDeFiltre.hpp"
#include "filtreMoyenne.hpp"
#include <iostream>

int main() {

	// On crée notre image img à partir du fichier fourni sur moodle
    Image img("cairo.pgm");

    // Test du constructeur par copie
    Image imgCopy = img;

    // On obtient les dimensions de l'image
	//Largeur
    size_t width = img.get_w();

	//Hauteur
    size_t height = img.get_h();

    std::cout << "Dimensions de l'image : " << width << " x " << height << std::endl;

	// On affiche la valeur d'un pixel 
    unsigned char pixelValue = img.get(5, 5);
    std::cout << "Valeur du pixel (5,5) : " << static_cast<int>(pixelValue) << std::endl;

    // On modifie un carré de pixels afin de voir clairement si notre modification marche correctement
    for (size_t i = height/2-50; i < height/2+50; ++i) {
        for (size_t j = width/2-50; j < width/2+50; ++j) {
            img.set(i, j, 159); //On set la couleur à 159 sur 255 arbitrairement 
    	}	
	}
    

    // Sauvegarder l'image modifiée
    img.write("cairo2.pgm");

    std::cout << "L'image a été modifiée et enregistrée avec succès." << std::endl;

	// Application du filtre Addition
    FiltreAddition filtre(90);  // On crée un filtre qui ajoute 30 à chaque pixel
    Image imgFiltree = imgCopy;     // On crée  une copie de l'image pour appliquer le filtre
    filtre.apply(imgFiltree);   // Application le filtre

	//Nous affichons la valeur du même pixel que précédement afin de comparer et savoir si notre filtre à agit correctement
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

    return 0;
}
