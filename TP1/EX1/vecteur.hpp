#ifndef VECTEUR_HPP
#define VECTEUR_HPP

class Vecteur {
	private:
		float x, y;  // Coordonnées du vecteur

	public:
	// Constructeurs
		Vecteur() : x(0), y(0) {}  // Constructeur par défaut
		Vecteur(float x, float y) : x(x), y(y) {}  // Constructeur avec coordonnées

		// Méthode pour afficher
		void affiche() const;

		// Méthode pour la norme du vecteur
		float norme() const;


		// Méthode pour additionner
		Vecteur* addition(const Vecteur& v) const;

		// Accesseurs
		float getX() const { return x; }
		float getY() const { return y; }
	
};

#endif // VECTEUR_HPP
