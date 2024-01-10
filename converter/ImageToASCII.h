//
// Created by User on 2024. 01. 08..
//

#ifndef MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_

#include <string>
#include <vector>
class ImageToASCII {
 public:
  explicit ImageToASCII(const std::string &file_path);
  virtual ~ImageToASCII();
  virtual std::string getASCIIString() = 0;
  virtual void saveASCIItoFile() = 0;
  virtual std::string guessFileType(std::string fileName) = 0;
  //resize
 protected:
  std::string filePath;
};

#endif //MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
