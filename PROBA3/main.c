#include "main.h"

int main(int argc, char* argv[]) {

	IplImage* image = cvCreateImage(cvSize(200, 150), IPL_DEPTH_8U, 3);
	SetImagePixels(pixel(100, 3), image);

	//IplImage* image = cvLoadImage("test.png", 1);
	Pixel pix;
	GetPixelValue(image, cvPoint(20, 40), &pix);

	SetPixelValue(image, cvPoint(20, 40), pixel(55, 3));

	CvPoint3D32f points[4];
	GetP4PAbidi(points);

	return 0;
}