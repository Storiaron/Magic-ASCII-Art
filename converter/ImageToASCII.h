//
// Created by User on 2024. 01. 08..
//

#ifndef MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_

#include <string>
#include <vector>
class ImageToASCII {
 public:
  explicit ImageToASCII(const std::string &file_path);
  virtual ~ImageToASCII();

  std::string getAsciiString();
  void saveASCIItoFile();
 protected:
  std::string filePath;
  std::vector<unsigned char> rawImage;
  unsigned width;
  unsigned height;
  double ratio{0};
};

#endif //MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
