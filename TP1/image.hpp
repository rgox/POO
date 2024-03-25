#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>  // Inclure pour std::string
#include <cstddef> // Inclure pour size_t

class Image {
public:
    // Constructeurs, destructeur, etc.
    Image(const std::string& fichier);
    Image(const Image& other);
    Image& operator=(const Image& other);
    ~Image();

    // Autres méthodes
    void load(const std::string& fichier);
    void write(const std::string& fichier) const;
    unsigned char get(int i, int j) const;
    void set(int i, int j, unsigned char valeur);
    size_t get_w() const;
    size_t get_h() const;

private:
    size_t w, h;
    unsigned char* data;

    void allocateData();
    void freeData();
};

#endif // IMAGE_HPP
