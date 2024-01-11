//
// Created by User on 2024. 01. 08..
//

#ifndef MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_

#include <string>
#include <vector>
#include "../AppConfig.h"
class ImageToASCII {
 public:
  explicit ImageToASCII(const Config &config);
  virtual ~ImageToASCII();

  std::string getAsciiString();
  void saveASCIItoFile();
  void displayAsciiString();
 protected:
  std::string outFilePath;
  std::string filePath;
  std::vector<unsigned char> rawImage;
  unsigned width;
  unsigned height;
  double ratio{1};
};

#endif //MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
