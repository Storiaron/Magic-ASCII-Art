//
// Created by User on 2024. 01. 08..
//

#ifndef MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_

#include <string>
class ImageToASCII {
 public:
  virtual std::string getASCIIString(std::string filePath) = 0;
};

#endif //MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
