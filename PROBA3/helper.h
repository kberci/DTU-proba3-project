#pragma once

#include "core_imgproc.h"
#include "perspective.h"
#include "point_selection.h"

int GetTargetPoseEstimate(const IplImage* raw_image, const CvMat* K, const CvMat* S, CvPoint2D32f points3678[4], CvPoint3D32f points[4], Euler* euler_deg, float* confidence);