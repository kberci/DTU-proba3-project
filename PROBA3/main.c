#include "main.h"

int main(int argc, char* argv[]) {

	//IplImage* image = cvCreateImage(cvSize(200, 150), IPL_DEPTH_8U, 3);
	//SetImagePixels(pixel(100, 3), image);

	//Pixel pix;
	//GetPixelValue(image, cvPoint(20, 40), &pix);

	//SetPixelValue(image, cvPoint(20, 40), pixel(55, 3));

	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	CV_MAT_ELEM(*S, float, 0, 1) = 77.5;
	CV_MAT_ELEM(*S, float, 0, 2) = 177.5;
	CV_MAT_ELEM(*S, float, 0, 3) = 162.0;
	CV_MAT_ELEM(*S, float, 1, 2) = 160.0;
	CV_MAT_ELEM(*S, float, 1, 3) = 191.5;
	CV_MAT_ELEM(*S, float, 2, 3) = 104.5;
	CvPoint2D32f P[4] = { // target points (x,y) in camera coordinates
		cvPoint2D32f(-2.214,-0.936),
		cvPoint2D32f(-2.564, 1.420),
		cvPoint2D32f(2.442, 1.948),
		cvPoint2D32f(2.657,-1.143)
	};
	CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
	GetP4PAbidi(S, P, points);

	return 0;
}