//
// Created by User on 2024. 01. 08..
//
#include <fstream>
#include "BMPToASCII.h"
//std::string BMPToASCII::getASCIIString(std::string filepath) {
//  BMP image;
//  const char* filepathPointer = stringToCharArr(filepath);
//  image.ReadFromFile(filepathPointer);
//  std::vector<std::vector<char>> charRepresentation = getCharRepresentation(image);
//  save(charRepresentation);
//  delete[] filepathPointer;
//  return "";
//}
const char* BMPToASCII::stringToCharArr(const std::string& convertee) {
  char* charArr = new char[convertee.size() + 1];
  std::strcpy(charArr, convertee.c_str());
  return charArr;
}
std::vector<std::vector<char>> BMPToASCII::getCharRepresentation(BMP decodedImage) {
  std::vector<std::vector<char>> greyScaleValues;
  for(int i = 0; i < decodedImage.TellHeight(); i++) {
    std::vector<char> rows;
    for(int j = 0; j < decodedImage.TellWidth(); j++) {
      RGBApixel pixel = decodedImage.GetPixel(j, i);
      int value = getGreyScaleValue(pixel.Red, pixel.Green, pixel.Blue);
      rows.push_back(convertValueToChar(value));
    }
    greyScaleValues.push_back(rows);
  }
  return greyScaleValues;
}
void BMPToASCII::save(const std::vector<std::vector<char>>& charRepresentation) {
  std::ofstream outputFile("../output/output.txt");
  if(!outputFile.is_open()) {
    std::cout<< "Error opening file"<<std::endl;
    return;
  }
  for(const auto& line : charRepresentation) {
    for(const auto& character : line) {
      outputFile << character;
      outputFile << character;
    }
    outputFile << '\n';
  }
  outputFile.close();
}
