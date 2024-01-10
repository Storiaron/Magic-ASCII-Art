#include "libraries/EasyBMP/EasyBMP.h"
#include "converter/PngToAscii.h"



int main(int argc, char *argv[]) {
  auto *converter = new PngToAscii("/home/k/Projects/Magic-ASCII-Art/pics/test2.png");
  converter->displayAsciiString();

  delete converter;
  return 0;
}