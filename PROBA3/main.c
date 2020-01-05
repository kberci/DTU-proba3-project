#include "main.h"


int main(int argc, char* argv[]) {
	char files[20][1000] = {
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/0.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/50.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/100.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/150.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/200.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/250.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/300.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_1.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_2.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_3.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_4.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_5.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_6.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_7.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_8.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_9.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_10.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_11.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_12.png",
		"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/2_3/random_13.png"
	};

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

	//char files[60][1000] = {
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_11.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_12.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_13.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_14.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_15.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_16.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_17.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_18.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_19.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_0_20.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_11.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_12.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_13.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_14.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_15.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_16.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_17.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_18.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_19.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_8_20.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_1.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_2.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_3.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_4.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_5.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_6.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_7.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_8.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_9.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_10.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_11.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_12.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_13.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_14.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_15.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_16.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_17.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_18.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_19.png",
	//	"D:/Kajatin/Uni/9 2019 Autumn/Image Analysis on Microcomputer/Project/img processing and abidi/images/0412/1/multiple_same_setup_min8_20.png",
	//};


	CvMat* K = cvCreateMat(3, 3, CV_32FC1); // matrix that stores the (static) intrinsic parameters of the camera
	GetCameraIntrinsicMatrix(K);
	
	CvMat* S = cvCreateMat(4, 4, CV_32FC1); // matrix that stores the distances of the LEDs from each other, constant
	GetDistancesMatrix(S);

	FILE* fp;
	fopen_s(&fp, "results_c.csv", "a");
	fprintf(fp, "file,rot_x,rot_y,rot_z,x,y,z,confidence,p0x,p0y,p1x,p1y,p2x,p2y,p3x,p3y\n");

	for (int i = 0; i < 20; i++) {
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