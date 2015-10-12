#include "ImagePlane.h"

ImagePlane::ImagePlane(STPoint3* LL, STPoint3* UL, STPoint3* LR, STPoint3* UR) {
	this->LL = LL;
	this->UL = UL;
	this->LR = LR;
	this->UR = UR;

	pixels = new Pixel[screenWidth * screenHeight];
}

//imX and imY are like x and y
STPoint3* ImagePlane::imgToWorld(int imX, int imY) {
	float xRatio = imX * 1.0 / screenWidth;
	float yRatio = imY * 1.0 / screenHeight;
	
	//bilinear interpolation
	STPoint3 bottom = *LL * (1 - xRatio) + STVector3(*LR * xRatio);
	STPoint3 top = *UL * (1 - xRatio) + STVector3(*UR * xRatio);
	return new STPoint3(bottom * (1 - yRatio) + STVector3(top * yRatio));
}

//imX and imY are like rows and columns!
void ImagePlane::setPixel(int imX, int imY, Pixel color) {
	pixels[imX * screenWidth + imY] = color;
}

void ImagePlane::writeImage() {
    /*STImage* screenshot = new STImage(;
    screenshot->Read(0,0);
    screenshot->Save("screenshot.jpg");*/
}