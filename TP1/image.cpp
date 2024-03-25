#include "image.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> 
#include <stdexcept> 
#include <fstream>


// Constructeur
Image::Image(const std::string& fichier) {
    load(fichier);
}

// Constructeur par copie
Image::Image(const Image& other) : w(other.w), h(other.h) {
    allocateData();
    std::copy(other.data, other.data + w * h, data);
}

// Opérateur d'assignement
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        freeData();
        w = other.w;
        h = other.h;
        allocateData();
        std::copy(other.data, other.data + w * h, data);
    }
    return *this;
}

// Destructeur
Image::~Image() {
    freeData();
}

void Image::allocateData() {
    data = new unsigned char[w * h];
}

void Image::freeData() {
    delete[] data;
}

unsigned char Image::get(int i, int j) const {
    // Assurez-vous que les indices sont dans la plage
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
    return data[i * w + j];
}

void Image::set(int i, int j, unsigned char valeur) {
    // Assurez-vous que les indices sont dans la plage
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
    data[i * w + j] = valeur;
}

size_t Image::get_w() const {
    return w;
}

size_t Image::get_h() const {
    return h;
}

void Image::load(const std::string& fname){
	
  std::ifstream f(fname.c_str());
  if(!f.good())
    throw std::runtime_error("Unable to open file for reading");

  std::string kind;
  f >> kind;
  if(kind != "P5")
    throw std::runtime_error("File is not a PGM image");

  f >> w >> h;
  unsigned max_value = 0;
  f >> max_value;

  if(data != nullptr)
    delete[] data;

  data = new unsigned char[w * h];
  f.read((char*)data, w * h);
}

void Image::write(const std::string& fname) const{
  std::ofstream ofs(fname);
  if(!ofs.good())
    throw std::runtime_error("Unable to open file for writing");

  ofs << "P5" << std::endl << w << " " << h << std::endl << 255 << std::endl;
  ofs.write((char*)data, w*h);

}