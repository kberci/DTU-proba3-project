#pragma once

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include<cv.h>
#include <highgui.h>

#include "error_codes.h"

#define TOTAL_POINTS 8


int CreateBinary(const IplImage* frame, IplImage* binary, const int threshold);