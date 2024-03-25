#include <iostream>
#include <fstream>
#include <cassert>
#include "image.hpp"

#include "filtre_addition.hpp"


Image::Image(int width, int height) // empty image of a given size
{
  w = width;
  h = height;
  data = new unsigned char[w * h];
}

Image& Image::operator=(const Image& other) // also used for copy ctr
{
  w = other.get_w();
  h = other.get_h();
  if(data != nullptr)
    delete data;
  data = new unsigned char[w * h];
  for(int i = 0; i < w*h ; i++)
    data[i] = other.data[i];
  return *this;
}

void Image::print() // mostly for debug
{
  for(int i = 0; i < w*h ; i++)
    std:: cout << (int)data[i] << " ";
  std:: cout << std::endl;
}

Image::Image(const Image& tocopy)
{
  *this = tocopy; //use assignment operator
}

Image::~Image() {
  if(data != nullptr)
    delete[] data;
}

void Image::load(const std::string& fname)
{
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

void Image::write(const std::string& fname) const
{
  std::ofstream ofs(fname);
  if(!ofs.good())
    throw std::runtime_error("Unable to open file for writing");

  ofs << "P5" << std::endl << w << " " << h << std::endl << 255 << std::endl;
  ofs.write((char*)data, w*h);
}

const unsigned char& Image::get(int i, int j) const
{
  int coord = j*w+i;
  if(coord > w*h || coord < 0)
    throw std::out_of_range("Index out of range while getting pixel data");
  return data[coord];
}

unsigned char& Image::get(int i, int j)
{
  int coord = j*w+i;
  if(coord > w*h || coord < 0)
    throw std::out_of_range("Index out of range while getting pixel data");
  return data[coord];
}


void Image::set(int i, int j, unsigned char val)
{
  int coord = j*w+i;
  if(coord > w*h || coord < 0)
    throw std::out_of_range("Index out of range while setting pixel data");
  data[coord] = val;
}

const unsigned char& Image::operator()(int i, int j) const
{
  int coord = j*w+i;
  if(coord > w*h || coord < 0)
    throw std::out_of_range("Index out of range while accessing image data");
  return data[coord];
}

unsigned char& Image::operator()(int i, int j)
{
  int coord = j*w+i;
  if(coord > w*h || coord < 0)
    throw std::out_of_range("Index out of range while accessing image data");
  return data[coord];
}

Image Image::operator+(const Image& other) const
{
  if(w != other.get_w() || h != other.get_h())
    throw std::runtime_error("Can't add images of different sizes");
  Image new_im(w,h);
  for(int i = 0; i < w*h ; i++) // 1D iteration is enough
  {
    int v = data[i] + other.data[i];
    if(v < 0)
      new_im.data[i] = 0;
    else if(v > 255)
      new_im.data[i] = 255;
    else
      new_im.data[i] = (unsigned char)v;
  }
  return new_im;
}


Image Image::operator-(const Image& other) const
{
  if(w != other.get_w() || h != other.get_h())
    throw std::runtime_error("Can't substract images of different sizes");
  Image new_im(w,h);
  for(int i = 0; i < w*h ; i++) // 1D iteration is enough
  {
    int v = data[i] - other.data[i];
    if(v < 0)
      new_im.data[i] = 0;
    else if(v > 255)
      new_im.data[i] = 255;
    else
      new_im.data[i] = (unsigned char)v;
  }
  return new_im;
}

Image Image::operator+(const int& val) const
{
  FiltreAddition f(val); // use FiltreAddition
  Image new_im(*this); // copy this
  f.apply(new_im); // apply filter
  return new_im; // return filtered copy
}

Image Image::operator-(const int& val) const
{
  return ((*this) + (-val)); // use operator+
}

/*int main(int argc, char**argvs)
{
  Image im("cairo.pgm");
  //im.print();
  im.write("test.pgm");
  return 0;
}*/
