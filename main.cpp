#include "libraries/EasyBMP/EasyBMP.h"
#include "converter/PngToAscii.h"



int main(int argc, char *argv[]) {
  auto *converter = new PngToAscii("/home/k/Projects/Magic-ASCII-Art/pics/test2.png");
  converter->loadImage();

  std::vector<std::vector<double>> gs(converter->height, std::vector<double>(converter->width / 4 + 1));

  std::string ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 0.2);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 0.4);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 1);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 1.6);
  std::cout << ascii;

  std::cout << ascii;

  delete converter;
  return 0;
}