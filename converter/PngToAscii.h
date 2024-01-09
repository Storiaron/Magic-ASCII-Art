#pragma once

#include "ImageToASCII.h"
class PngToAscii : public ImageToASCII {
 public:
  explicit PngToAscii(const std::string &file_path);
  ~PngToAscii() override;
  std::string getASCIIString() override;
  void saveASCIItoFile() override;
  std::string guessFileType(std::string fileName) override;
  void loadImage();
  std::vector<unsigned char> rawImage;
  unsigned width;
  unsigned height;
 private:
};
