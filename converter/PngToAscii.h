#pragma once

#include "ImageToASCII.h"
class PngToAscii : public ImageToASCII {
 public:
  explicit PngToAscii(const Config &config);
  ~PngToAscii() override;
  void loadImage();

 private:
};
