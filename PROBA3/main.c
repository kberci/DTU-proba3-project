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
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> BERCI --------------------------------------//
	//IplImage* image = cvLoadImage("base.png", 0);
	//IplImage* image = cvLoadImage("5_rot.png", 0);	
	IplImage* image = cvLoadImage("13m_rot.png", 0);
	IplImage* image_binary = cvCloneImage(image);
	CreateBinary(image, image_binary, 180);
	if (image == NULL) {
		printf("Image not found!");
		return -1;
	}
	uchar* binary_data = (uchar*)image_binary->imageData;

	CvPoint start = cvPoint(0, 0);
	Array point_set[total_points];
	CvPoint centers[total_points];

	FindAllCenters(image_binary, start, point_set, centers);

	CvPoint points3678[4];
	ChoosePoints3678(centers, points3678);
	
	//points3678 has the 4 points' coordinates in the same order as showing in the name (3, 6, 7, 8)
	
	// -------------------------------------- BERCI <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//

	CvPoint2D32f P[4] = { // target points (x,y) in camera coordinates
		cvPoint2D32f(-0.3916,-0.209),
		cvPoint2D32f(-0.5346,0.4642),
		cvPoint2D32f(0.275,0.4642),
		cvPoint2D32f(0.2816,-0.3454)
	};

	CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
	GetP4PAbidi(S, P, points);

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


	// -------------------------------------- BERCI VISUALIZATION--------------------------------------------//
	// output image conversion to 3 channels (so that contour can be coloured)
	IplImage* output = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 3);
	cvConvertImage(image, output, CV_GRAY2BGR);

	for (int point_num = 0; point_num < total_points; point_num++) {
		// draw contour
		for (int i = 1; i < point_set[point_num].used; i++) {
			// draw contour line to output image
			CvPoint p1 = cvPoint(point_set[point_num].array[i - 1].x, point_set[point_num].array[i - 1].y);
			CvPoint p2 = cvPoint(point_set[point_num].array[i].x, point_set[point_num].array[i].y);
			cvLine(output, p1, p2, cvScalar(0, 0, 255, 0), 1, 8, 0);
		}
		// draw center
		for (int i = 1; i < point_set[point_num].used; i++) {
			// draw center to output image
			int cross_size = 5;
			cvLine(output, cvPoint(centers[point_num].x - cross_size, centers[point_num].y - cross_size),
				cvPoint(centers[point_num].x + cross_size, centers[point_num].y + cross_size), cvScalar(0, 255, 0, 0), 2, 0, 0);
			cvLine(output, cvPoint(centers[point_num].x - cross_size, centers[point_num].y + cross_size),
				cvPoint(centers[point_num].x + cross_size, centers[point_num].y - cross_size), cvScalar(0, 255, 0, 0), 2, 0, 0);
		}
	}
	int cross_size = 2;
	for (int point_num = 0; point_num < 4; point_num++) {
		// cross on selected points:
		cvLine(output, cvPoint(points3678[point_num].x - cross_size, points3678[point_num].y - cross_size),
			cvPoint(points3678[point_num].x + cross_size, points3678[point_num].y + cross_size), cvScalar(255, 0, 0, 0), 2, 0, 0);
		cvLine(output, cvPoint(points3678[point_num].x - cross_size, points3678[point_num].y + cross_size),
			cvPoint(points3678[point_num].x + cross_size, points3678[point_num].y - cross_size), cvScalar(255, 0, 0, 0), 2, 0, 0);
		cross_size += 3;
	}

	// show images
	cvShowImage("Original image", image);
	cvShowImage("Contoured image", output);

	cvWaitKey(0);
	cvReleaseImage(&image);
	cvDestroyAllWindows();
	for (int point_num = 0; point_num < total_points; point_num++) {
		FreeArray(&point_set[point_num]);
	}
	// -------------------------------------- BERCI VISUALIZATION --------------------------------------------//
	return 0;
}