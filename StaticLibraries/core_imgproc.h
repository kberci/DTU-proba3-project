#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <cv.h>
#include <highgui.h>

#include "error_codes.h"

#define TOTAL_POINTS 8
#define M_PI acos(-1.0)


int CreateBinary(const IplImage* frame, IplImage* binary, const int threshold);
int UndistortImage(const IplImage* distorted, IplImage* undistorted, const CvMat* K);
int InterpolatePixelValue(IplImage* image, CvPoint2D32f p);
int GetCameraIntrinsicMatrix(CvMat* K);