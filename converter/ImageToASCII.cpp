#include <cmath>
#include <iostream>
#include <fstream>
#include "ImageToASCII.h"
#include "../util/UtilityCollection.h"

ImageToASCII::ImageToASCII(const Config &config) : filePath(config.filePath), ratio(config.ratio) {}

ImageToASCII::~ImageToASCII() = default;

std::string ImageToASCII::getAsciiString() {
  if (ratio <= 0) throw std::exception();

  std::string result;

  if (width > 0 && height > 0) {
    unsigned w2 = floor(ratio * width);
    unsigned h2 = height * w2 / width;
    h2 = (h2 * 2) / 3; //compensate for non-square characters in terminal

    for (unsigned y = 0; y < h2; y++) {
      for (unsigned x = 0; x < w2; x++) {
        unsigned x2 = x * width / w2;
        unsigned y2 = y * height / h2;
        int r = rawImage[y2 * width * 4 + x2 * 4 + 0];
        int g = rawImage[y2 * width * 4 + x2 * 4 + 1];
        int b = rawImage[y2 * width * 4 + x2 * 4 + 2];
        int a = rawImage[y2 * width * 4 + x2 * 4 + 3];
        int lightness = ((r + g + b) / 3) * a / 255;

        result += convertValueToChar(lightness);
      }
      result += '\n';
    }
  }
  return result;
}

void ImageToASCII::saveASCIItoFile() {
  std::ofstream outputFile("../output/output.txt");
  if (!outputFile.is_open()) {
    std::cout << "Error opening file" << std::endl;
    return;
  }
  outputFile << getAsciiString();
}

void ImageToASCII::displayAsciiString() {
  std::cout << getAsciiString();
}

