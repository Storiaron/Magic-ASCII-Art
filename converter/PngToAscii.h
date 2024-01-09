//
// Created by k on 09/01/24.
//

#pragma once

#include "ImageToASCII.h"
class PngToAscii : public ImageToASCII {
 public:
  std::string getASCIIString() override;
  void saveASCIItoFile() override;
  std::string guessFileType(std::string fileName) override;
};
