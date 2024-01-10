//
// Created by User on 2024. 01. 08..
//
#include <fstream>
#include "BMPToASCII.h"
const char* BMPToASCII::stringToCharArr(const std::string& convertee) {
  char* charArr = new char[convertee.size() + 1];
  std::strcpy(charArr, convertee.c_str());
  return charArr;
}
void BMPToASCII::createRawImage(BMP decodedImage) {
  height = decodedImage.TellHeight();
  width = decodedImage.TellWidth();
  for(int i = 0; i < decodedImage.TellHeight(); i++) {
    for(int j = 0; j < decodedImage.TellWidth(); j++) {
      RGBApixel pixel = decodedImage.GetPixel(j, i);
      rawImage.push_back(pixel.Red);
      rawImage.push_back(pixel.Green);
      rawImage.push_back(pixel.Blue);
      rawImage.push_back(pixel.Alpha);
    }
  }
}
