//
// Created by User on 2024. 01. 08..
//

#ifndef MAGIC_ASCII_ART_CONVERTER_BMPTOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_BMPTOASCII_H_

#include <vector>
#include <cstring>
#include <iostream>
#include "ImageToASCII.h"
#include "../libraries/EasyBMP/EasyBMP_BMP.h"
#include "../libraries/EasyBMP/EasyBMP_DataStructures.h"
#include "../util/UtilityCollection.h"
class BMPToASCII : public ImageToASCII{
 public:
  explicit BMPToASCII(const Config &config);
 private:
  void createRawImage(BMP decodedImage);
  const char* stringToCharArr(const std::string& convertee);
};

#endif //MAGIC_ASCII_ART_CONVERTER_BMPTOASCII_H_
