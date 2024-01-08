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
using namespace std;

int main( int argc, char* argv[] )
{
  cout << endl
       << "Using EasyBMP Version " << _EasyBMP_Version_ << endl << endl
       << "Copyright (c) by the EasyBMP Project 2005-6" << endl
       << "WWW: http://easybmp.sourceforge.net" << endl << endl;

  BMP Text;
  Text.ReadFromFile(argv[1]);
  Text.WriteToFile("../output/test1.txt");
  return 0;
}