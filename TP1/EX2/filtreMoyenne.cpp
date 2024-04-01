#include "filtreMoyenne.hpp"

FiltreMoyenne::FiltreMoyenne(int taille) : Filtre("Moyenne"), taille(taille) {}

void FiltreMoyenne::apply(Image& i) const {
    Image imgCopy = i; // Faire une copie de l'image originale pour le calcul de toute les moyennes

    for (size_t y = 0; y < i.get_w(); ++y) { //on parcours tout les pixels de l'image 
        for (size_t x = 0; x < i.get_h(); ++x) {
            int somme = 0;
            int count = 0;

            // Parcourir la zone de n x n autour du pixel
            for (int dy = -taille; dy <= taille; ++dy) {
                for (int dx = -taille; dx <= taille; ++dx) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // Vérifier si le pixel voisin est dans l'image
                    if (nx >= 0 && nx < static_cast<int>(i.get_h()) && ny >= 0 && ny < static_cast<int>(i.get_w())) {
                        somme += imgCopy.get(nx, ny);
                        count++;
                    }
                }
            }

            // nouvelle valeur du pixel
            if (count != 0) {
                i.set(x, y, static_cast<unsigned char>(somme / count));
            }
        }
    }
}
