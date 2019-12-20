#include "helper.h"

int GetTargetPoseEstimate(const IplImage* raw_image, const CvMat* K, const CvMat* S, CvPoint2D32f points3678[4], CvPoint3D32f points[4], Euler* euler_deg, float* confidence) {
	IplImage* undistorted = cvCreateImage(cvSize(raw_image->width, raw_image->height), IPL_DEPTH_8U, 1);
	UndistortImage(raw_image, undistorted, K);

	


	// calculate histogram for single channel
	uchar* und_data = (uchar*)undistorted->imageData;
	int histogram[256] = { 0 };
	for (int j = 0; j < undistorted->height; j++) {
		for (int i = 0; i < undistorted->width; i++) {
			int pixel_value = und_data[i + j * undistorted->widthStep];
			if (pixel_value > 100) histogram[pixel_value] += 1;
		}
	}

	// initialize histogram image
	IplImage* hist = cvCreateImage(cvSize(256, 256), IPL_DEPTH_8U, 1);
	int h_width = hist->width;
	int h_height = hist->height;
	int h_step = hist->widthStep;
	uchar* h_data = (uchar*)hist->imageData;
	for (int j = 0; j < h_height; j++) {
		for (int i = 0; i < h_width; i++) {
			h_data[i + j * h_step] = 255;
		}
	}

	// calculate max value in histogram array
	int h_max = 0;
	int max_index = 0;
	for (int i = 0; i < 256; i++) {
		int val = histogram[i];
		if (h_max < val) {
			h_max = val;
			max_index = i;
		}
	}

	// normalize histogram array to [0-1] * scaler
	int scaler = 255;
	for (int i = 0; i < 256; i++) {
		histogram[i] = (int)(((float)histogram[i] / (float)h_max) * scaler);
	}

	// draw histogram lines
	for (int i = 0; i < 256; i++) {
		CvPoint pt1 = cvPoint(i, 256);
		CvPoint pt2 = cvPoint(i, 256 - histogram[i]);
		cvLine(hist, pt1, pt2, cvScalarAll(40),1,8,0);
	}

	//cvSaveImage("histogram.png", hist, 0);







	
	
	IplImage* image_binary = cvCloneImage(undistorted);
	int threshold = max_index - 10;
	threshold = 150;
	ERROR ecode = CreateBinary(undistorted, image_binary, threshold);
	if (ERREVAL(ecode)) {
		EPRINT(ecode);
		return -1;
	}

	CvPoint start = cvPoint(0, 0);
	Array point_set[TOTAL_POINTS];
	CvPoint2D32f centers[TOTAL_POINTS];
	ecode = FindAllCenters(image_binary, start, point_set, centers);
	if (ERREVAL(ecode)) {
		EPRINT(ecode);
		return -1;
	}

	ChoosePoints3678(centers, points3678);

	CvPoint2D32f C[4]; // target points (x,y) in camera coordinates
	PixelToCameraCoordinate(points3678, C, K);

	GetP4PAbidi(S, C, points, confidence);

	CvMat* R = cvCreateMat(3, 3, CV_32FC1);
	CalculateRotationMatrix(points, R);

	Euler euler;
	RotationMatrixToEuler(R, &euler);

	RadiansToDegreesEulers(euler, euler_deg);

	//TODO: implement reprojection or maybe use matlab for that

	//VisualiseContours(undistorted, point_set, centers, points3678);


	return EOK;
}


//TODO: finish implementation of visualisation function here
int VisualiseContours(const IplImage* raw_image, const Array point_set[TOTAL_POINTS], const CvPoint2D32f centers[TOTAL_POINTS], const CvPoint2D32f points3678[4]) {
	// output image conversion to 3 channels (so that contour can be coloured)
	IplImage* output = cvCreateImage(cvSize(raw_image->width, raw_image->height), IPL_DEPTH_8U, 3);
	cvConvertImage(raw_image, output, CV_GRAY2BGR);

	for (int point_num = 0; point_num < TOTAL_POINTS; point_num++) {
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
	cvShowImage("Original image", raw_image);
	cvShowImage("Contoured image", output);

	cvWaitKey(0);
	cvReleaseImage(&raw_image);
	cvDestroyAllWindows();
	for (int point_num = 0; point_num < TOTAL_POINTS; point_num++) {
		FreeArray(&point_set[point_num]);
	}
}