#pragma once

#include "st.h"
#include "Light.h"

using namespace std;
typedef STColor3f Pixel;
#define screenWidth 512
#define screenHeight 512


//Represents virtual window into scene 
class ImagePlane {

	public:
		//constructor: defines imageplane as four corners relative to camera
		ImagePlane(STPoint3* LL, STPoint3* UL, STPoint3* LR, STPoint3* UR); 

		//calculate the world coordinates of a point with the specified image coordinates
		STPoint3* imgToWorld(int imX, int imY);

		//set pixel color
		void setPixel(int imX, int imY, Pixel color);
		
		//write stored results to image file
		void writeImage();



		//array of pixels of ImagePlane
		Pixel* pixels;
	private:
		//four corners of ImagePlane
		STPoint3* LL;
		STPoint3* UL;
		STPoint3* LR;
		STPoint3* UR;

		/*int screenWidth;
		int screenHeight;*/
};