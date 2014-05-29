/*********************************************************************
NAME: CARSON TUNNA
COURSE: COMP 2333 - 002
ASG#: 3
FILE NAME: intutil.cpp
DUE: WEDNESDAY MARCH 9TH, 2011 10:00 PM
**********************************************************************

Program Summary:

   This program attempts appy the droste effect on a 2 dimensional picture inside
   a region read from the user. Given the four coordinates, upper X - Y and
   lower X - Y, the program will recursively call several functions to redraw the
   image in specified region.

Assumptions:
   The region input will have parallel sides

*******************************************************************************/
#include <iostream>
#include <Magick++.h>

#include "intutil.h"
#include "droste.h"

using namespace Magick;
using namespace std;

int main()

{

    int
		x = 0,  // Coordinates x and y initialized to 0,0 (origin).
		y = 0,
		upperX, // Upper/Lower represents recursive region
		upperY,
		lowerX,
		lowerY,
		width,  // Width/Heighht of new image.
		height;

    Image
		startImage,
		endImage;

    string
		inputFile,
		outputFile;

    cout << "Enter input filename: " << endl;
    cin >> inputFile;
	
    startImage.read(inputFile);

    readInt("Enter upper left x and y (e.g. '255 64'): ", upperX, upperY);
    readInt("Enter lower right x and y (e.g. '400 70'): ", lowerX, lowerY);

    cout << "Enter output filename: " << endl;
    cin >> outputFile;

    // Calculating Width/Height of new image.
    width = startImage.columns();
    height = startImage.rows();

    // Creating new image.
    endImage.extent (Geometry (width, height) );
    traversePixels(x, y, upperX, upperY, lowerX, lowerY, startImage, endImage);

    endImage.write(outputFile);

    return 0;

}

