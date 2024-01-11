//
// Created by Tomi on 2024. 01. 10..
//

#pragma once

#include "ImageToASCII.h"
class JPEGtoASCII : public ImageToASCII {
 public:
  JPEGtoASCII(const Config &config) : ImageToASCII(config) {
    loadFile();
  };
  std::string getAsciiString() override;
 private:
  void loadFile();
};
