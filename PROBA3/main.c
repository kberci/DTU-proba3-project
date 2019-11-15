#include "main.h"

int main(int argc, char* argv[]) {

	//IplImage* image = cvCreateImage(cvSize(200, 150), IPL_DEPTH_8U, 3);
	//SetImagePixels(pixel(100, 3), image);

	//Pixel pix;
	//GetPixelValue(image, cvPoint(20, 40), &pix);

	//SetPixelValue(image, cvPoint(20, 40), pixel(55, 3));

	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	GetDistancesMatrix(S);

	//CvPoint2D32f P[4] = { // target points (x,y) in camera coordinates
	//	cvPoint2D32f(-2.214,-0.936),
	//	cvPoint2D32f(-2.564, 1.420),
	//	cvPoint2D32f(2.442, 1.948),
	//	cvPoint2D32f(2.657,-1.143)
	//};
	
	CvPoint2D32f P[4] = { // target points (x,y) in camera coordinates
		cvPoint2D32f(0.2816,-0.3454),
		cvPoint2D32f(0.275,0.4642),
		cvPoint2D32f(-0.3916,-0.209),
		cvPoint2D32f(-0.5346,0.4642)
	};

	CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
	GetP4PAbidi(S, P, points);

	IplImage* base = cvLoadImage("base.png", 0);
	IplImage* rot5 = cvLoadImage("5_rot.png", 0);

	// cvPoint(col,row) <- this is native to OpenCv
	CvPoint points_L[3] = {
		cvPoint(1280,611),
		cvPoint(1277,979),
		cvPoint(974,673)
	};

	CvPoint points_R[3] = {
		cvPoint(1208,648),
		cvPoint(1181,1016),
		cvPoint(900,690)
	};

	Affine T;
	CalculateAffineTransform(points_L, points_R, &T);
	CvPoint2D32f pl;
	ApplyAffineTransform(cvPoint2D32f(909,979), T, &pl);

	return 0;
}