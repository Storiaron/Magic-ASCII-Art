/*************************************************
*                                                *
*  EasyBMP Cross-Platform Windows Bitmap Library *
*                                                *
*  Author: Paul Macklin                          *
*   email: macklin01@users.sourceforge.net       *
* support: http://easybmp.sourceforge.net        *
*                                                *
*          file: EasyBMPsample.cpp               *
*    date added: 03-31-2006                      *
* date modified: 12-01-2006                      *
*       version: 1.06                            *
*                                                *
*   License: BSD (revised/modified)              *
* Copyright: 2005-6 by the EasyBMP Project       *
*                                                *
* description: Sample application to demonstrate *
*              some functions and capabilities   *
*                                                *
*************************************************/

#include "libraries/EasyBMP/EasyBMP.h"
#include "converter/PngToAscii.h"
using namespace std;

int main( int argc, char* argv[] )
{
  auto *converter = new PngToAscii("/home/k/Projects/Magic-ASCII-Art/pics/test1.png");
  converter->loadImage();

  delete converter;
  return 0;
}