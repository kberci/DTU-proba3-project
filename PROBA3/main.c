#include "main.h"


int main(int argc, char* argv[]) {
	IplImage* raw_image = cvLoadImage("image_6997_0.png", 0);
	if (raw_image == NULL) {
		printf("ERROR: Image not found!");
		return -1;
	}

	CvMat* K = cvCreateMat(3, 3, CV_32FC1); // matrix that stores the (static) intrinsic parameters of the camera
	GetCameraIntrinsicMatrix(K);
	
	IplImage* undistorted = cvCreateImage(cvSize(raw_image->width, raw_image->height), IPL_DEPTH_8U, 1);
	UndistortImage(raw_image, undistorted, K);

	//IplImage* difference = cvCreateImage(cvSize(raw_image->width, raw_image->height), IPL_DEPTH_8U, 1);
	//uchar* data_difference = (uchar*)difference->imageData;
	//uchar* data_corrected = (uchar*)undistorted->imageData;
	//uchar* data_raw = (uchar*)raw_image->imageData;
	//for (int j = 0; j < difference->height; j++) {
	//	for (int i = 0; i < difference->width; i++) {
	//		int index = i + j * difference->widthStep;
	//		float val = abs(data_raw[index] - data_corrected[index]);
	//		if (val > 0) {
	//			val += 200;
	//		}
	//		data_difference[index] = val;
	//	}
	//}
	
	IplImage* image_binary = cvCloneImage(undistorted);
	ERROR ecode = CreateBinary(undistorted, image_binary, 180);
	if (ERREVAL(ecode)) {
		EPRINT(ecode);
		return -1;
	}

	CvPoint start = cvPoint(0, 0);
	Array point_set[TOTAL_POINTS];
	CvPoint2D32f centers[TOTAL_POINTS];

	FindAllCenters(image_binary, start, point_set, centers);

	CvPoint2D32f points3678[4];
	ChoosePoints3678(centers, points3678);
	
	CvPoint2D32f C[4]; // target points (x,y) in camera coordinates
	PixelToCameraCoordinate(points3678, C, K);

	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	GetDistancesMatrix(S);

	CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
	GetP4PAbidi(S, C, points);




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
	// -------------------------------------- BERCI VISUALIZATION --------------------------------------------//

	return 0;
}





CvCapture* capture;

//TODO: out of memory for array in the while loop
//TODO: make the point selection process robust: if there are no 8 points return error etc.
//TODO: process image better, morphology, reduce blob size etc.
//TODO: check point selection method for errors (i.e. how well it finds the 4 point correspondances)
//TODO: check if grabbed image from camera needs to be flipped or not

int test(int argc, char* argv[]) {
	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	GetDistancesMatrix(S);

	CvMat* K = cvCreateMat(3, 3, CV_32FC1); // matrix that stores the (static) intrinsic parameters of the camera
	GetCameraIntrinsicMatrix(K);

	capture = cvCaptureFromCAM(0); // initialize capture device
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, (double)2304);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, (double)1536);

	IplImage* frame;

	while (1) {
		if (!cvGrabFrame(capture)) { // capture a frame
			printf("Could not grab a frame\n\7");
			break;
		}
		frame = cvRetrieveFrame(capture, 0);
		if (frame != NULL) {
			CvSize size = cvSize(frame->width, frame->height);
			IplImage* image = cvCreateImage(size, frame->depth, 1);
			cvConvertImage(frame, image, CV_BGR2GRAY);
			IplImage* image_binary = cvCloneImage(image);

			ERROR ecode = CreateBinary(image, image_binary, 180);
			if (ERREVAL(ecode)) {
				EPRINT(ecode);
				return -1;
			}

			CvPoint start = cvPoint(0, 0);
			Array point_set[TOTAL_POINTS];
			CvPoint2D32f centers[TOTAL_POINTS];

			FindAllCenters(image_binary, start, point_set, centers);

			CvPoint2D32f points3678[4];
			ChoosePoints3678(centers, points3678);

			CvPoint2D32f C[4]; // target points (x,y) in camera coordinates
			PixelToCameraCoordinate(points3678, C, K);

			CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
			GetP4PAbidi(S, C, points);
			printf("z: %.6f\n",points[0].z / 6.0);

			IplImage* output = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 3);
			cvConvertImage(image, output, CV_GRAY2BGR);

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
			//cvShowImage("Original image", image);
			cvShowImage("Contoured image", output);


			int key = cvWaitKey(1000 / 30);
			if (key == 27) {
				break;
			}
		}
	}

	//cvReleaseImage(&image);
	cvDestroyAllWindows();
	//for (int point_num = 0; point_num < TOTAL_POINTS; point_num++) {
	//	FreeArray(&point_set[point_num]);
	//}
	
	return 0;
}