//
// Created by User on 2024. 01. 09..
//

#ifndef MAGIC_ASCII_ART_UTIL_UTILITYCOLLECTION_H_
#define MAGIC_ASCII_ART_UTIL_UTILITYCOLLECTION_H_

#include <cmath>

static std::string guessFileType(std::string fileName) {

}

static int getGreyScaleValue(const int red, const int green, const int blue) {
  return floor((0.3 * red) + (0.59 * green) + (0.11 * blue));
}

static char convertValueToChar(int greyScaleValue) {
  if (greyScaleValue == 255) {
    return ' ';
  }
  if (greyScaleValue >= 227) {
    return '.';
  }
  if (greyScaleValue >= 199) {
    return '*';
  }
  if (greyScaleValue >= 171) {
    return ':';
  }
  if (greyScaleValue >= 143) {
    return 'o';
  }
  if (greyScaleValue >= 115) {
    return '&';
  }
  if (greyScaleValue >= 87) {
    return '8';
  }
  if (greyScaleValue >= 59) {
    return '#';
  }
  return '@';
}

#endif //MAGIC_ASCII_ART_UTIL_UTILITYCOLLECTION_H_
