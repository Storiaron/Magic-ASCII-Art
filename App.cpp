//
// Created by k on 10/01/24.
//

#include <cstring>
#include <iostream>
#include "App.h"
#include "converter/BMPToASCII.h"
#include "converter/PngToAscii.h"
#include "converter/JPEGtoASCII.h"

int App::run(int argc, char **argv) {
  parseArgs(argc, argv);
  getConverter();
  if (converter->haveOutput()) converter->saveASCIItoFile();
  else converter->displayAsciiString();
  return EXIT_SUCCESS;
}

void App::parseArgs(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
        case 'f':config.filePath = argv[i + 1];
          break;
        case 't':
          setFileType(std::string (argv[i + 1]));
          break;
        case 'o':config.outFilePath = argv[i + 1];
          break;
        case 'r': char *ptr;
          config.ratio = std::strtod(argv[i + 1], &ptr);
          break;
      }
    }
  }

  if (config.fileType == null) {
    std::string extension = config.filePath.substr(config.filePath.find_last_of('.') + 1);
    setFileType(extension);
  }
}
void App::getConverter() {
  switch (config.fileType) {
    case bmp: converter = new BMPToASCII(config);
      break;
    case png: converter = new PngToAscii(config);
      break;
    case jpg: converter = new JPEGtoASCII(config);
      break;
    case null:std::cerr << "Something is wrong with the extension";
      exit(EXIT_FAILURE);
  }
}
void App::setFileType(const std::string &extension) {
  if (extension == "bmp") config.fileType = bmp;
  else if (extension == "png") config.fileType = png;
  else if (extension == "jpg") config.fileType = jpg;
}

