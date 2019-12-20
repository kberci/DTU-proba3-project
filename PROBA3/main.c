#include "main.h"


int main(int argc, char* argv[]) {
	//char files[20][1000] = {
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/0.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/50.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/100.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/150.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/200.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/250.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/300.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_11.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_12.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_13.png"
	//};
	//char files[21][1000] = {
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/-1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/0.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/horizontal/10.png"
	//};
	//char files[21][1000] = {
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_-1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_0.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/4/vertical/closer_10.png"
	//};
	char files[60][1000] = {
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_1.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_2.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_3.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_4.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_5.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_6.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_7.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_8.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_9.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_10.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_11.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_12.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_13.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_14.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_15.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_16.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_17.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_18.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_19.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_20.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_1.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_2.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_3.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_4.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_5.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_6.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_7.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_8.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_9.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_10.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_11.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_12.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_13.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_14.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_15.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_16.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_17.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_18.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_19.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_20.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_1.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_2.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_3.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_4.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_5.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_6.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_7.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_8.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_9.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_10.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_11.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_12.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_13.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_14.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_15.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_16.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_17.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_18.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_19.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_20.png",
	};


	CvMat* K = cvCreateMat(3, 3, CV_32FC1); // matrix that stores the (static) intrinsic parameters of the camera
	GetCameraIntrinsicMatrix(K);
	
	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	GetDistancesMatrix(S);

	FILE* fp;
	fopen_s(&fp, "results_c.csv", "a");
	fprintf(fp, "file,rot_x,rot_y,rot_z,x,y,z,confidence,p0x,p0y,p1x,p1y,p2x,p2y,p3x,p3y\n");

	for (int i = 0; i < 60; i++) {
		printf("Processing %d ...  ", i);
		// read image
		IplImage* raw_image = cvLoadImage(files+i, 0);
		if (raw_image == NULL) {
			printf("ERROR: Image not found!");
			return -1;
		}

		CvPoint2D32f points3678[4];
		CvPoint3D32f points[4];
		Euler euler_deg;
		float confidence;
		GetTargetPoseEstimate(raw_image, K, S, points3678, points, &euler_deg, &confidence);

		//printf("Relative orientation and position of target wrt camera\n");
		//printf("Confidence %f\n", confidence);
		//printf("rotz: %f roty: %f rotx: %f\n", euler_deg.z, euler_deg.y, euler_deg.x);
		//printf("x: %f y: %f z: %f\n", points[1].x, points[1].y, points[1].z);

		fprintf(fp, "%s,%f,%f,%f,%f,%f,%f,%f,", files+i,euler_deg.x, euler_deg.y, euler_deg.z, points[1].x, points[1].y, points[1].z, confidence);
		fprintf(fp, "%f,%f,%f,%f,%f,%f,%f,%f\n", points3678[0].x, points3678[0].y, points3678[1].x, points3678[1].y, points3678[2].x, points3678[2].y, points3678[3].x, points3678[3].y);
		printf("Done\n");
	}

	fclose(fp);
	return 0;
}



































CvCapture* capture;

//TODO: out of memory for array in the while loop
//TODO: make the point selection process robust: if there are no 8 points return error etc.
//TODO: process image better, morphology, reduce blob size etc.
//TODO: check point selection method for errors (i.e. how well it finds the 4 point correspondances)
//TODO: check if grabbed image from camera needs to be flipped or not

int main_loop(int argc, char* argv[]) {
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
			IplImage* raw_image = cvCreateImage(size, frame->depth, 1);
			cvConvertImage(frame, raw_image, CV_BGR2GRAY);


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
			ERROR ecode = CreateBinary(undistorted, image_binary, 240);
			if (ERREVAL(ecode)) {
				EPRINT(ecode);
				continue;
			}

			CvPoint start = cvPoint(0, 0);
			Array point_set[TOTAL_POINTS];
			CvPoint2D32f centers[TOTAL_POINTS];
			ecode = FindAllCenters(image_binary, start, point_set, centers);
			if (ERREVAL(ecode)) {
				EPRINT(ecode);
				printf("Skipping frame!\n");
				continue;
			}

			CvPoint2D32f points3678[4];
			ChoosePoints3678(centers, points3678);

			CvPoint2D32f C[4]; // target points (x,y) in camera coordinates
			PixelToCameraCoordinate(points3678, C, K);

			CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
			GetDistancesMatrix(S);

			float confidence;
			CvPoint3D32f points[4]; // returned 4 points (x,y,z) are stored in this array
			GetP4PAbidi(S, C, points, &confidence);

			CvMat* R = cvCreateMat(3, 3, CV_32FC1);
			CalculateRotationMatrix(points, R);

			Euler euler;
			RotationMatrixToEuler(R, &euler);

			Euler euler_deg;
			RadiansToDegreesEulers(euler, &euler_deg);

			//TODO: implement reprojection or maybe use matlab for that

			printf("Relative orientation and position of target wrt camera\n");
			printf("rotz: %f roty: %f rotx: %f\n", euler_deg.z, euler_deg.y, euler_deg.x);
			printf("x: %f y: %f z: %f\n", points[1].x, points[1].y, points[1].z);




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