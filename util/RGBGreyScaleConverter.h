//
// Created by User on 2024. 01. 09..
//

#ifndef MAGIC_ASCII_ART_UTIL_RGBGREYSCALECONVERTER_H_
#define MAGIC_ASCII_ART_UTIL_RGBGREYSCALECONVERTER_H_

class RGBGreyScaleConverter {
 public:
  static double getGreyScaleValue(const int red,const int green,const int blue) {
    return (0.3 * red) + (0.59 * green) + (0.11 * blue);
  }
};

#endif //MAGIC_ASCII_ART_UTIL_RGBGREYSCALECONVERTER_H_
