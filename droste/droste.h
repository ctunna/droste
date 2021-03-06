#ifndef DROSTE_H
#define DROSTE_H

#include <Magick++.h>

using namespace Magick;

//  This function gets colours from input image.
Color getColor(int x, int y, const int upperX, const int upperY, const int lowerX, const int lowerY, const Image startImage, Image &endImage, int &depthCount);

// This function traverses each pixel of the image.
void traversePixels(int x, int y, const int upperX, const int upperY, const int lowerX, const int lowerY, const Image startImage, Image &endImage);

const int DEPTH_LIMIT = 20;

#endif
