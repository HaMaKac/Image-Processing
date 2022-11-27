//
// Created by rafal on 01.11.2022.
//

#ifndef MAIN_CPP_O_H
#define MAIN_CPP_O_H
#include "../CImg.h"
using namespace cimg_library;

void uolis_operator(CImg<unsigned char> image) {
    CImg<unsigned char> newImage = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int o=0;o<=2;o++)
            {
                newImage(x, y,o) = (unsigned char)log2(0.8*pow(image(x, y,o),4)/(image(x-1, y,o)*image(x+1, y,o)*image(x, y-1,o)*image(x, y+1,o)));
            }
        }
    }
    newImage.save_bmp("..\\images\\Uolis.bmp");
}

#endif //MAIN_CPP_O_H
