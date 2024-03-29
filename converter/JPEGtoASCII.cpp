//
// Created by Tomi on 2024. 01. 10..
//

#include <fstream>
#include <cmath>
#include <iostream>
#include "JPEGtoASCII.h"
#include "../libraries/JPEG_Decoder/jpeg_decoder.h"
#include "../util/UtilityCollection.h"
void JPEGtoASCII::loadFile() {
  std::ifstream is(filePath, std::ifstream::binary);

  if (is) {
    is.seekg(0, std::ifstream::end);
    int length = is.tellg();
    is.seekg(0, std::ifstream::beg);

    auto *buffer = new unsigned char[length];

    is.read(reinterpret_cast<char *>(buffer), length);
    is.close();

    Jpeg::Decoder d(buffer, length);
    if (d.GetResult() == 0) {
      this->width = d.GetWidth();
      this->height = d.GetHeight();
      this->rawImage.assign(d.GetImage(), d.GetImage() + d.GetImageSize());
    } else
      std::cout << "Error converting jpg: " << d.GetResult() << std::endl;

    delete[] buffer;
  }
}
std::string JPEGtoASCII::getAsciiString() {
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
        int r = rawImage[y2 * width * 3 + x2 * 3 + 0];
        int g = rawImage[y2 * width * 3 + x2 * 3 + 1];
        int b = rawImage[y2 * width * 3 + x2 * 3 + 2];

        result += convertValueToChar(getGreyScaleValue(r,g,b));
      }
      result += '\n';
    }
  }
  return result;
}
