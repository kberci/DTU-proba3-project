#pragma once

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include<cv.h>
#include <highgui.h>

#include "error_codes.h"

#define TEST 15
#define total_points 8

typedef struct {
	int count;
	CvScalar val;
} Pixel;

inline Pixel pixel(double val0123, int channel) {
	Pixel pix;
	pix.count = channel;

	//int elem = (int)(sizeof(&val0123) / sizeof(double));
	//double values[4];
	//for (int i = 0; i < elem; i++) {
	//	values[i] = val0123[i];
	//}
	//for (int i = elem; i < 4; i++) {
	//	values[i] = 0;
	//}
	//pix.val = cvScalar(values[0], values[1], values[2], values[3]);

	pix.val = cvScalarAll(val0123);
	return pix;
}

int GetPixelValue(const IplImage* frame, const CvPoint at, Pixel* out);
int SetPixelValue(const IplImage* frame, const CvPoint at, const Pixel pix);
int SetImagePixels(const Pixel color, IplImage* out);
int CreateBinary(const IplImage* img, const IplImage* binary, int threshold);