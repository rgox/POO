#include "image.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> 
#include <stdexcept> 
#include <fstream>

	//Fonctions utiles pour la suite

//Allocaion de la mémoire
void Image::allocateData() {
	// On alloue une zone de memoire de taille w*h pour stocker les pixels de l'image postérieurement
    data = new unsigned char[w * h];
}

//Libération de la mémoire
void Image::freeData() {
	//On utilise la fontion delete[] afin de desalouer la mémoire occupée dans data
    delete[] data;
}


	//CONSTRUCTEURS

// Constructeur par défaut
Image::Image(const std::string& fichier) {
    load(fichier); 
}

// Constructeur par copie
Image::Image(const Image& other) : w(other.w), h(other.h) {
	//On aloue la mémoire nécessaire
    allocateData();

	//On copie dans la mémoire alouée les données du fichier rentré en argument 
    std::copy(other.data, other.data + w * h, data); 
}

// Opérateur d'assignement
Image& Image::operator=(const Image& other) {
    if (this != &other) {
		//On libère la memoire actuelle
        freeData(); 

		//On copie chaque attribut de l'objet passé en argument
        w = other.w; 
        h = other.h;

		//On aloue la mémoire nécessaire
        allocateData();

		//On copie dans la mémoire alouée les données du fichier rentré en argument 
        std::copy(other.data, other.data + w * h, data);
    }
    return *this;
}



	// DESTRUCTEUR

Image::~Image() {
	//On libère la memoire actuelle
    freeData();
}




	// GETTERS  

//Get de la valeur d'un pixel
unsigned char Image::get(int i, int j) const {
    // On vérifie que les indices correspondent bien à un pixel de l'image
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
	// On renvoie le contenu du pixel i*j
    return data[i * w + j];
}


//Get de la valeur de la largeure
size_t Image::get_w() const {
    return w;
}

//Get de la valeur de la hauteur
size_t Image::get_h() const {
    return h;
}

//Set de la valeur d'un pixel
void Image::set(int i, int j, unsigned char valeur) {
    // On vérifie que les indices correspondent bien à un pixel de l'image
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
	// On modifie le contenu du pixel i*j
    data[i * w + j] = valeur;
}

//Chargement d'une image à partir du nom d'un fichier
void Image::load(const std::string& fichier)
{
	// Ouverture du fichier en lecture binaire
	std::ifstream f(fichier.c_str());
	

	//Test que l'ouverture ait été bien réalisée
	if(!f.good())
		throw std::runtime_error("Unable to open file for reading");
	
	//On test que l'image soit bien de type PGM
	std::string kind;
	f >> kind;
	if(kind != "P5")
		throw std::runtime_error("File is not a PGM image");
		
	// Lecture des dimensions de l'image
	f >> w >> h;	
	
	// On alloue la mémoire nécessaire à stocker la nouvelle image
	data = new unsigned char[w * h];

	// On lit les données de l'image ouverte précédement en les stockant dans data
	f.read((char*)data, w * h);
}

// Sauvegarde d'une image dans un fichier
void Image::write(const std::string& fichier) const{
	//On crée un objet de "output" afin de sauvegarder notre nouvelle image dedans
  	std::ofstream ofs(fichier);

	//On test qu'on l'ai bien crée
  	if(!ofs.good())
    	throw std::runtime_error("Unable to open file for writing");

	//On écrit le header de l'image (type P5 et taille w*h ainsi que la valeure maximale du pixel 255)
  	ofs << "P5" << std::endl << w << " " << h << std::endl << 255 << std::endl;

	//Et finalement on écrit notre image dans le output ouvert précédement 
  	ofs.write((char*)data, w*h);
  
}