#include <iostream>
#include "PngToAscii.h"
#include "../libraries/LodePNG/lodepng.h"

std::string PngToAscii::getASCIIString() {
  return std::string();
}
void PngToAscii::saveASCIItoFile() {

}
std::string PngToAscii::guessFileType(std::string fileName) {
  return std::string();
}

void PngToAscii::loadImage() {
  unsigned error = lodepng::decode(rawImage, width, height, filePath);
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}
PngToAscii::PngToAscii(const std::string &file_path) : ImageToASCII(file_path) {}
PngToAscii::~PngToAscii() = default;
