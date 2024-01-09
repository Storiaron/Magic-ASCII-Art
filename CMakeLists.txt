cmake_minimum_required(VERSION 3.26)
project(Magic_ASCII_Art)

set(CMAKE_CXX_STANDARD 17)

add_executable(Magic_ASCII_Art main.cpp
        libraries/EasyBMP/EasyBMP.cpp
        libraries/EasyBMP/EasyBMP.h
        libraries/EasyBMP/EasyBMP_BMP.h
        libraries/EasyBMP/EasyBMP_DataStructures.h
        libraries/EasyBMP/EasyBMP_VariousBMPutilities.h
        converter/ImageToASCII.cpp
        converter/ImageToASCII.h
        converter/BMPToASCII.cpp
        converter/BMPToASCII.h
        util/RGBGreyScaleConverter.h
        util/RGBGreyScaleConverter.h)
