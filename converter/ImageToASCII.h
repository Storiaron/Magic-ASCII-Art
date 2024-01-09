#ifndef MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
#define MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_

#include <string>
#include <vector>
class ImageToASCII {
 public:
  explicit ImageToASCII(const std::string &file_path);
  virtual std::string getASCIIString() = 0;
  virtual void saveASCIItoFile() = 0;
  virtual std::string guessFileType(std::string fileName) = 0;
  //resize
 protected:
  std::string filePath;
  std::vector<unsigned char> rawImage;
};

#endif //MAGIC_ASCII_ART_CONVERTER_IMAGETOASCII_H_
