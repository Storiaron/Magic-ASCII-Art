//
// Created by k on 10/01/24.
//

#include <cstring>
#include <iostream>
#include "App.h"
#include "converter/BMPToASCII.h"
#include "converter/PngToAscii.h"

int App::run(int argc, char **argv) {
  parseArgs(argc, argv);
  getConverter();
  converter->displayAsciiString();
  return 0;
}
void App::parseArgs(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
        case 'f':config.filePath = argv[i + 1];
          break;
        case 't':
          if (strcmp(argv[i + 1], "bmp") == 0) config.fileType = bmp;
          else if (strcmp(argv[i + 1], "png") == 0) config.fileType = png;
          else if (strcmp(argv[i + 1], "jpg") == 0) config.fileType = jpg;
          break;
        case 'o':config.outFilePath = argv[i + 1];
          break;
        case 'r': char *ptr; config.ratio = std::strtod(argv[i + 1], &ptr);
          break;
      }
    }
  }

  if (config.fileType == null) {
    std::string extension = config.filePath.substr(config.filePath.find_last_of('.') + 1);
    if (extension == "bmp") config.fileType = bmp;
    else if (extension == "png") config.fileType = png;
    else if (extension == "jpg") config.fileType = jpg;
  }
}
void App::getConverter() {
  switch (config.fileType) {
    case bmp: converter = new BMPToASCII(config);
      break;
    case png: converter = new PngToAscii(config);
      break;
    case jpg:
    case null:
      std::cerr << "Something is wrong with the extension";
      exit(EXIT_FAILURE);
  }
}

