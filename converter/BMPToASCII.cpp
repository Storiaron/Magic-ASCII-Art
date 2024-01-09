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
  for(int i = 0; i < decodedImage.TellHeight(); i++) {
    std::vector<double> rows;
    for(int j = 0; j < decodedImage.TellWidth(); j++) {
      RGBApixel pixel = decodedImage.GetPixel(j, i);
      double value = RGBGreyScaleConverter::getGreyScaleValue(pixel.Red, pixel.Green, pixel.Blue);
      std::cout<< value <<'\n';
      rows.push_back(value);
    }
    greyScaleValues.push_back(rows);
  }
  return greyScaleValues;
}