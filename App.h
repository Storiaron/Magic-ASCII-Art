//
// Created by k on 10/01/24.
//

#pragma once

#include <string>
#include "converter/ImageToASCII.h"
#include "AppConfig.h"
class App {
 public:
  int run(int argc, char **argv);
 private:
  ImageToASCII *converter;
  Config config;
  void parseArgs(int argc, char **argv);
  void getConverter();
};
