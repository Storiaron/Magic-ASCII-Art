#pragma once

#include "ImageToASCII.h"
class PngToAscii : public ImageToASCII {
 public:
  explicit PngToAscii(const std::string &file_path);
  ~PngToAscii() override;
  void loadImage();

 private:
};
