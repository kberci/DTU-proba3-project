#include "perspective.h"

int GetP4PAbidi(CvPoint3D32f out[4]) {
	//cvCreateMat(3,3,CV_MAT_MAGIC_VAL);
	
	// determined once(measure)
	//S = [0, 77.5, 177.5, 162;
	//77.5, 0, 160, 191.5;
	//177.5, 160, 0, 104.5;
	//162, 191.5, 104.5, 0];

	//float s12 = CV_MAT_ELEM(S, float, 0, 1);
	//float s13 = CV_MAT_ELEM(S, float, 0, 2);
	//float s14 = CV_MAT_ELEM(S, float, 0, 3);
	//float s23 = CV_MAT_ELEM(S, float, 1, 2);
	//float s24 = CV_MAT_ELEM(S, float, 1, 3);
	//float s34 = CV_MAT_ELEM(S, float, 2, 3);
	//
	//float s41 = s14;

	// TODO: these are input to the function as shown above
	float s12 = 77.5;
	float s13 = 177.5;
	float s14 = 162.0;
	float s23 = 160.0;
	float s24 = 191.5;
	float s34 = 104.5;

	float s41 = s14;

	// needs to be evaluated only once (constant)
	float A1 = sqrt(pow((pow(s12,2) + pow(s13,2) + pow(s23,2)),2) - 2 * (pow(s12,4) + pow(s13,4) + pow(s23,4))) / 4.0;
	float A2 = sqrt(pow((pow(s12,2) + pow(s14,2) + pow(s24,2)),2) - 2 * (pow(s12,4) + pow(s14,4) + pow(s24,4))) / 4.0;
	float A3 = sqrt(pow((pow(s13,2) + pow(s14,2) + pow(s34,2)),2) - 2 * (pow(s13,4) + pow(s14,4) + pow(s34,4))) / 4.0;
	float A4 = sqrt(pow((pow(s23,2) + pow(s24,2) + pow(s34,2)),2) - 2 * (pow(s23,4) + pow(s24,4) + pow(s34,4))) / 4.0;

	// TODO: this should be an input parameter
	float x1 = -2.214;
	float y1 = -0.936;
	float x2 = -2.564;
	float y2 = 1.42;
	float x3 = 2.442;
	float y3 = 1.948;
	float x4 = 2.657;
	float y4 = -1.143;

	float B1 = x1 * (y3 - y2) + y1 * (x2 - x3) + y2 * x3 - x2 * y3;
	float B2 = x1 * (y4 - y2) + y1 * (x2 - x4) + y2 * x4 - x2 * y4;
	float B3 = x1 * (y4 - y3) + y1 * (x3 - x4) + y3 * x4 - x3 * y4;
	float B4 = x2 * (y4 - y3) + y2 * (x3 - x4) + y3 * x4 - x3 * y4;

	float C12 = (B3 * A4) / (A3 * B4);
	float C13 = (B2 * A4) / (A2 * B4);
	float C14 = (B1 * A4) / (A1 * B4);
	float C23 = (B2 * A3) / (A2 * B3);
	float C24 = (B1 * A3) / (A1 * B3);
	float C34 = (B1 * A2) / (A1 * B2);
	float C21 = 1.0 / C12;
	float C31 = 1.0 / C13;
	float C41 = 1.0 / C14;
	float C32 = 1.0 / C23;
	float C42 = 1.0 / C24;
	float C43 = 1.0 / C34;

	float H12s = pow((x1 - C12 * x2), 2) + pow((y1 - C12 * y2), 2);
	float H13s = pow((x1 - C13 * x3), 2) + pow((y1 - C13 * y3), 2);
	float H14s = pow((x1 - C14 * x4), 2) + pow((y1 - C14 * y4), 2);
	float H23s = pow((x2 - C23 * x3), 2) + pow((y2 - C23 * y3), 2);
	float H24s = pow((x2 - C24 * x4), 2) + pow((y2 - C24 * y4), 2);
	float H34s = pow((x3 - C34 * x4), 2) + pow((y3 - C34 * y4), 2);
	float H21s = pow((x2 - C21 * x1), 2) + pow((y2 - C21 * y1), 2);
	float H31s = pow((x3 - C31 * x1), 2) + pow((y3 - C31 * y1), 2);
	float H41s = pow((x4 - C41 * x1), 2) + pow((y4 - C41 * y1), 2);
	float H32s = pow((x3 - C32 * x2), 2) + pow((y3 - C32 * y2), 2);
	float H42s = pow((x4 - C42 * x2), 2) + pow((y4 - C42 * y2), 2);
	float H43s = pow((x4 - C43 * x3), 2) + pow((y4 - C43 * y3), 2);
	
	float f = 13.0;

	float F1 = sqrt(pow(x1, 2) + pow(y1, 2) + pow(f, 2));
	float F2 = sqrt(pow(x2, 2) + pow(y2, 2) + pow(f, 2));
	float F3 = sqrt(pow(x3, 2) + pow(y3, 2) + pow(f, 2));
	float F4 = sqrt(pow(x4, 2) + pow(y4, 2) + pow(f, 2));

	float d1 = s12 * F1 * pow(H12s + pow(f, 2) * pow((1 - C12), 2), -0.5);
			//s13 * F1 * (H13s + f ^ 2 * (1 - C13) ^ 2) ^ (-0.5) + ...
			//s14 * F1 * (H14s + f ^ 2 * (1 - C14) ^ 2) ^ (-0.5) + ...
			//(s23 * F1 * (H23s + f ^ 2 * (1 - C23) ^ 2) ^ (-0.5)) / C12 + ...
			//(s24 * F1 * (H24s + f ^ 2 * (1 - C24) ^ 2) ^ (-0.5)) / C12 + ...
			//(s34 * F1 * (H34s + f ^ 2 * (1 - C34) ^ 2) ^ (-0.5)) / C13) / 6

	float d2 = (C12 * F2 / F1) * d1;
	float d3 = (C13 * F3 / F1) * d1;
	float d4 = (C14 * F4 / F1) * d1;

	float R12 = sqrt(H12s + pow(f, 2) * pow((1 - C12), 2));
	float R23 = sqrt(H23s + pow(f, 2) * pow((1 - C23), 2));
	float R34 = sqrt(H34s + pow(f, 2) * pow((1 - C34), 2));
	float R41 = sqrt(H41s + pow(f, 2) * pow((1 - C41), 2));

	CvPoint3D32f P1 = cvPoint3D32f(-x1 * s12 * pow(R12, -1), -y1 * s12 * pow(R12, -1), f * (s12 * pow(R12, -1) + 1));
	CvPoint3D32f P2 = cvPoint3D32f(-x2 * s23 * pow(R23, -1), -y2 * s23 * pow(R23, -1), f * (s23 * pow(R23, -1) + 1));
	CvPoint3D32f P3 = cvPoint3D32f(-x3 * s34 * pow(R34, -1), -y3 * s34 * pow(R34, -1), f * (s34 * pow(R34, -1) + 1));
	CvPoint3D32f P4 = cvPoint3D32f(-x4 * s41 * pow(R41, -1), -y4 * s41 * pow(R41, -1), f * (s41 * pow(R41, -1) + 1));

	out[0] = P1;
	out[1] = P2;
	out[2] = P3;
	out[3] = P4;

	return EOK;
}