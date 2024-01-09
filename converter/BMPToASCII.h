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
#include "../util/RGBGreyScaleConverter.h"
class BMPToASCII : public ImageToASCII{
 public:
  std::string getASCIIString(std::string filepath) override;
 private:
  std::vector<std::vector<double>> getGreyScaleValue(BMP decodedImage);
  const char* stringToCharArr(const std::string& convertee);
};

#endif //MAGIC_ASCII_ART_CONVERTER_BMPTOASCII_H_