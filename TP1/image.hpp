#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>  // Inclure pour std::string
#include <cstddef> // Inclure pour size_t

class Image {
	public:
		// Constructeur par défaut
		Image(const std::string& fichier); 

		//Contructeur par copie
		Image(const Image& other); 

		//Assignement
		Image& operator=(const Image& other); 

		//Destructeur
		~Image(); 

		// Autres méthodes
		//Load: Prend en argument un nom de fichier et charge l’image
		void load(const std::string& fichier); 

		//Write: Ecrit l’image sur le disque dur dans le fichier dont le nom est donné en argument
		void write(const std::string& fichier) const; 

		//Get: Renvoie la valeur du pixel de coordonnées (i,j) (sans permettre de la modifier)
		unsigned char get(int i, int j) const; 

		//Set: Modifie la valeur du pixel de coordonnées (i,j)
		void set(int i, int j, unsigned char valeur); 
		
		// Accesseurs
		size_t get_w() const;
		size_t get_h() const;

	private:
		size_t w, h;
		unsigned char* data;
		
		//Autres fonctions  privées
		void allocateData();
		void freeData();
};

#endif // IMAGE_HPP
