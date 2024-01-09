//
// Created by User on 2024. 01. 08..
//
#include "BMPToASCII.h"
std::string BMPToASCII::getASCIIString(std::string filepath) {
  BMP image;
  const char* filepathPointer = stringToCharArr(filepath);
  image.ReadFromFile(filepathPointer);
  std::vector<std::vector<double>> greyScaleValues = getGreyScaleValue(image);
  delete[] filepathPointer;
  return std::string();
}
const char* BMPToASCII::stringToCharArr(const std::string& convertee) {
  char* charArr = new char[convertee.size() + 1];
  std::strcpy(charArr, convertee.c_str());
  return charArr;
}
std::vector<std::vector<double>> BMPToASCII::getGreyScaleValue(BMP decodedImage) {
  std::vector<std::vector<double>> greyScaleValues;
  for(int i = 0; i < decodedImage.TellWidth(); i++) {
    for(int j = 0; j < decodedImage.TellHeight(); j++) {
      RGBApixel pixel = decodedImage.GetPixel(i, j);
      double value = RGBGreyScaleConverter::getGreyScaleValue(pixel.Red, pixel.Green, pixel.Blue);
      greyScaleValues.at(i).at(j) = value;
    }
  }
  return greyScaleValues;
}