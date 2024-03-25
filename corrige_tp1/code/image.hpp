#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <stdexcept>

class Image
{
  public:
    Image(const std::string & s)
    {
      load(s);
    }
    Image(int width, int height); // empty image
    Image& operator=(const Image& other);
    Image(const Image& tocopy);
    ~Image();
    int get_w() const {return w;};
    int get_h() const {return h;};
    void write(const std::string& fname) const;
    void load(const std::string& fname);
    const unsigned char& get(int i, int j) const;
    unsigned char& get(int i, int j);
    void set(int i, int j, unsigned char val);
    void print(); // DEBUG
    const unsigned char& operator()(int i, int j) const;
    unsigned char& operator()(int i, int j);
    // Operators
    Image operator+(const Image& other) const;
    Image operator-(const Image& other) const;
    Image operator+(const int& val) const;
    Image operator-(const int& val) const;
  protected:
    int w, h;
    unsigned char * data = nullptr;
};

#endif
