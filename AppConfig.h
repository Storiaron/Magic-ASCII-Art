//
// Created by k on 10/01/24.
//

#pragma once

#include <string>
#include "FileType.h"
struct Config {
  std::string filePath;
  FileType fileType{null};
  std::string outFilePath;
  double ratio{1.0};
};
