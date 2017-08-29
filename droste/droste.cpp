#include "droste.h"

using namespace Magick;
using namespace std;

Color getColor(int x, int y, const int upperX, const int upperY, const int lowerX, const int lowerY, const Image startImage, int depthCount)
{
  Color pixel;

  auto imageHeight = startImage.rows();
  auto imageWidth = startImage.columns();
  auto regionWidth = lowerX - upperX;
  auto regionHeight = lowerY - upperY;

  if (depthCount >= DEPTH_LIMIT) {
    return pixel;
  }

  if ((( x >= upperX && x <= lowerX ) && ( y >= upperY && y <= lowerY ))) {
    // remap pixels to specified region.
    auto newX = static_cast<int>(((x - upperX)/(static_cast<double>(regionWidth))) * (imageWidth));
    auto newY = static_cast<int>(((y - upperY)/(static_cast<double>(regionHeight))) * (imageHeight));

    pixel = getColor(newX, newY, upperX, upperY, lowerX, lowerY, startImage, ++depthCount);
  } else { // Base case - not in region
    pixel = startImage.pixelColor(x, y);
  }

  return pixel;
}

void traversePixels(int x, int y, const int upperX, const int upperY, const int lowerX, const int lowerY, const Image startImage, Image &endImage)
{
  auto imageHeight = startImage.rows();
  auto imageWidth = startImage.columns();

  Color pixel;

  // Base Case
  // if at the end of the image.
  if (y >= imageHeight) {
    return;
  } else {
    // General Case
    // start at x and get color for each pixel if not at the end of width.
    for (; x < imageWidth; x++) {
      pixel = getColor(x, y, upperX, upperY, lowerX, lowerY, startImage, 0);
      endImage.pixelColor(x, y, pixel);
    }
    // move x back to 0 and down one on y-axis.
    traversePixels(x = 0, y + 1, upperX, upperY, lowerX, lowerY, startImage, endImage);
  }
}











