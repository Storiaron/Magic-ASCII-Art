#include "libraries/EasyBMP/EasyBMP.h"
#include "converter/PngToAscii.h"

std::string displayAsciiArt(const std::vector<unsigned char> &image, unsigned w, unsigned h, double ratio) {
  if(ratio <= 0) throw std::exception();

  std::string result;

  if (w > 0 && h > 0) {
    unsigned w2 = floor(ratio * w);
    unsigned h2 = h * w2 / w;
    h2 = (h2 * 2) / 3; //compensate for non-square characters in terminal

    for (unsigned y = 0; y < h2; y++) {
      for (unsigned x = 0; x < w2; x++) {
        unsigned x2 = x * w / w2;
        unsigned y2 = y * h / h2;
        int r = image[y2 * w * 4 + x2 * 4 + 0];
        int g = image[y2 * w * 4 + x2 * 4 + 1];
        int b = image[y2 * w * 4 + x2 * 4 + 2];
        int a = image[y2 * w * 4 + x2 * 4 + 3];
        int lightness = ((r + g + b) / 3) * a / 255;

        if (lightness > 224) result += '@';
        else if (lightness > 190) result += '#';
        else if (lightness > 160) result += '8';
        else if (lightness > 128) result += '&';
        else if (lightness > 80) result += 'o';
        else if (lightness > 48) result += ':';
        else if (lightness > 32) result += '*';
        else if (lightness > 16) result += '.';
        else result += ' ';
      }
      result += '\n';
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  auto *converter = new PngToAscii("/home/k/Projects/Magic-ASCII-Art/pics/test2.png");
  converter->loadImage();

  std::vector<std::vector<double>> gs(converter->height, std::vector<double>(converter->width / 4 + 1));

  std::string ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 0.2);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 0.4);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 1);
  std::cout << ascii;
  ascii = displayAsciiArt(converter->rawImage, converter->width, converter->height, 1.6);
  std::cout << ascii;

  std::cout << ascii;

  delete converter;
  return 0;
}