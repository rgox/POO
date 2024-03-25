#include <fstream>
#include <cassert>
int test_ofs(int argc, char **argv)
{
  std::ofstream ofs("/tmp/test.txt");
  if(!ofs.good())
    throw std::runtime_error("Unable to open file for writing");
  int x = 42;
  std::string h = "hello world";
  ofs << 42 << " " << h << std::endl; // equivalent printf
  unsigned char* buffer = new unsigned char[256];
  for (size_t i = 0; i < 256; ++i)
    buffer[i] = 42;
  ofs.write((char*)buffer, 256); // equivalent fwrite
  delete[] buffer;
}
int main(int argc, char**argv)
{
  test_ofs(argc, argv);
  std::ifstream ifs("/etc/hosts");
  if(!ifs.good())
    throw std::runtime_error("Unable to open file for reading");
  int x;
  std::string s;
  ifs >> x >> s; // lit x et s, equivalent scanf
  unsigned char * buffer = new unsigned char[256];
  ifs.read((char*)buffer, 256); // equivalent fread
  delete[] buffer;
}
