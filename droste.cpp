#include "droste.h"

using namespace Magick;
using namespace std;

//  This function gets colours from input image.
Color getColor(int x, int y, const int upperX, const int upperY, const int lowerX,
               const int lowerY, const Image startImage, Image &endImage, int &depthCount);

// This function traverses each pixel of the image.
void traversePixels(int x, int y, const int upperX, const int upperY, const int lowerX,
                    const int lowerY, const Image startImage, Image &endImage);

const int DEPTH_LIMIT = 10;

/*************************************************************************
Function Name: getColor

Purpse: The purpose of this function is to get a color from the startImage
        and return determined colour to the traversePixels() function.

Method: See function body.

Input Parameters: int x - an X coordinate on startImage

                  int y - a Y coordinate on startImage

                  const int upperX - upper X coordinate of the
                  recursive region specified

                  const int upperY - upper Y coordinate
                  of the recursive region specified

                  const int lowerX - lower X coordinate
                  of the recursive region specified

                  const int lowerY - lower Y coordinate
                  of the recursive region specified

                  const Image startImage - the initial image defined
                  by the users input file name 

Output Parameters: None.

Returns: This function returns a Color taken from startImage.

**************************************************************************/

Color getColor(int x, int y, const int upperX, const int upperY, const int lowerX,
			   const int lowerY, const Image startImage, int &depthCount)
{
	Color
		pixel;

	int
		imageHeight = startImage.rows(),
		imageWidth = startImage.columns(),
		regionWidth = lowerX - upperX,
		regionHeight = lowerY - upperY,
		newX,
		newY;


	depthCount++;

	if( depthCount >= DEPTH_LIMIT ) {
		return pixel;
    }
	
	if((( x >= upperX && x <= lowerX ) && ( y >= upperY && y <= lowerY ))) {
		// remap pixels to specified region.
		newX = static_cast<int>( ( (x - upperX)/( static_cast<double>(regionWidth) ) ) * (imageWidth) );
		newY = static_cast<int>( ( (y - upperY)/( static_cast<double>(regionHeight) ) ) * (imageHeight) );

		pixel = getColor(newX, newY, upperX, upperY, lowerX, lowerY, startImage, depthCount);
    } else { // Base case - not in region
		pixel = startImage.pixelColor(x, y);
	}
	
	return pixel;
}

/*************************************************************************
Function Name: traversePixels

Purpse: The purpose of this function is to traverse the pixels of the image
        specified by the user.

Method: See function body.

Input Parameters: int x - X coordinate on startImage

                  int y - Y coordinate on startImage

                  const int upperX - upper X coordinate of the
                  recursive region specified 

                  const int upperY -  upper Y coordinate of the
                  recursive region specified 

                  const int lowerX - lower X coordinate of the
                  recursive region specified 

                  const int lowerY -  lower Y coordinate of the
                  recursive region specified 

                  const Image startImage - initial image defined by
                  the users input file name 

                  const Image endImage - final output image defined by
                  the users output file name 

Output Parameters: int x - X coordinate on startImage.

                   int y - Y coordinate on startImage.

Returns: This function returns void.
**************************************************************************/
void traversePixels(int x, int y, const int upperX, const int upperY,
					const int lowerX, const int lowerY, const Image startImage,
					Image &endImage)
{

	int
		imageHeight = startImage.rows(),
		imageWidth = startImage.columns(),
		depthCount;

	Color
		pixel;

	// Base Case
	// if at the end of the image.
	if(y >= imageHeight)
    {
		return;
    } else { 	// General Case

		// start at x and get color for each pixel if not at the end of width.
		for(; x < imageWidth; x++)
        {
			depthCount = 1;
			pixel = getColor(x, y, upperX, upperY, lowerX, lowerY, startImage, depthCount);
			endImage.pixelColor(x, y, pixel);
        }
		// move x back to 0 and down one on y-axis.
		traversePixels(x = 0, y + 1, upperX, upperY, lowerX, lowerY, startImage, endImage);
    }

}
