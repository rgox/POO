#ifndef VECTEUR_HPP
#define VECTEUR_HPP

class Vecteur {
	private:
		float x, y;  // Coordonnées du vecteur

	public:
	// Constructeurs
		Vecteur() : x(0), y(0) {}  // Constructeur par défaut
		Vecteur(float x, float y) : x(x), y(y) {}  // Constructeur avec coordonnées

		// Méthode pour afficher les coordonnées
		void affiche() const;

		// Méthode calculant la norme du vecteur
		float norme() const;


		// Méthode pour additionner avec un autre vecteur
		Vecteur* addition(const Vecteur& v) const;

		// Accesseurs
		float getX() const { return x; }
		float getY() const { return y; }
		// Accesseurs non-const (pour modifications éventuelles)
		float& getX() { return x; }
		float& getY() { return y; }
};

#endif // VECTEUR_HPP
