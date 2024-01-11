#include <iostream>
#include "PngToAscii.h"
#include "../libraries/LodePNG/lodepng.h"

PngToAscii::PngToAscii(const Config &config) : ImageToASCII(config) {
  loadImage();
}

PngToAscii::~PngToAscii() = default;

void PngToAscii::loadImage() {
  unsigned error = lodepng::decode(rawImage, width, height, filePath);
  if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

