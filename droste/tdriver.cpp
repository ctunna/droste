#include <iostream>
#include <Magick++.h>

#include "droste.h"

using namespace Magick;
using namespace std;

int main(int argc, char **argv)
{
  InitializeMagick(*argv);
  
  int upperX;
  int upperY;
  int lowerX;
  int lowerY;

  string inputFile;
  string outputFile;

  cout << "Enter input filename: " << endl;
  cin >> inputFile;

  Image startImage;
  startImage.read(inputFile);

  cout << "Enter upper left x and y (e.g. '255 64'): " << endl;
  cin >> upperX >> upperY;

  cout << "Enter lower right x and y (e.g. '400 70'): " << endl;
  cin >> lowerX >> lowerY;

  cout << "Enter output filename: " << endl;
  cin >> outputFile;

  auto width = startImage.columns();
  auto height = startImage.rows();
  
  Geometry geometry(width, height);
  Image endImage(geometry, "white");

  traversePixels(0, 0, upperX, upperY, lowerX, lowerY, startImage, endImage);

  endImage.write(outputFile);

  return 0;
}

