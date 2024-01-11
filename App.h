//
// Created by k on 10/01/24.
//

#pragma once

#include <string>
#include "converter/ImageToASCII.h"
#include "AppConfig.h"
class App {
 public:
  int run(const int &argc, char **argv);
 private:
  ImageToASCII *converter;
  Config config;
  void parseArgs(const int &argc, char **argv);
  void getConverter();
  void setFileType(const std::string &extension);
};
