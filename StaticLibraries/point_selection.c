#include "point_selection.h"


int InitArray(Array* a, size_t initialSize) {
	a->array = (CvPoint*)malloc(initialSize * sizeof(CvPoint));
	a->used = 0;
	a->size = initialSize;

	return EOK;
}


int InsertArray(Array* a, CvPoint element) {
	if (a->used == a->size) {
		a->size *= 2;
		a->array = (CvPoint*)realloc(a->array, a->size * sizeof(CvPoint));
	}
	a->array[a->used++] = element;

	return EOK;
}


int FreeArray(Array* a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;

	return EOK;
}


int FindStart(const IplImage* image, CvPoint* start) {
	uchar* image_data = (uchar*)image->imageData;

	for (int j = 0; j < image->height; j++) {
		for (int i = 0; i < image->width; i++) {
			int pixel_value = image_data[i + j * image->widthStep];
			if (pixel_value == 255) {
				start->x = i;
				start->y = j;
				return EOK;
			}
		}
	}

	return EINVALID;
}


int FindContour(const IplImage* frame, CvPoint start, Array* point_set, CvPoint from, CvPoint p) {
	// recursion base case: if 'p' == 'start'
	if ((p.x == start.x) && (p.y == start.y)) {
		return 1;
	}

	// first call to this function
	if (from.x == NULL) {
		from = cvPoint(start.x - 1, start.y);
		p = start;
	}

	InsertArray(point_set, p); // insert pixel into contour array
	double angle = atan2(p.y - from.y, p.x - from.x); // angle used to determine the first pixel neighbor to check
	uchar* data = (uchar*)frame->imageData;

	// check 3 neighbors
	for (int k = 0; k < 3; k++) {
		//TODO: handle case where indices are out of bounds
		int check_y = p.y - (int)cos(angle + (k * M_PI / 2));
		int check_x = p.x + (int)sin(angle + (k * M_PI / 2));
		int value = data[check_x + check_y * frame->widthStep];

		if (value == 255) {
			int ret = FindContour(frame, start, point_set, p, cvPoint(check_x, check_y), false);
			if (ret) return 1;
		}
	}

	return 0;
}


int FindBorder(const IplImage* image, CvPoint start, Array* point_set) {
	int ws = image->widthStep;
	uchar* image_data = (uchar*)image->imageData;

	CvPoint currentPoint = cvPoint(NULL, NULL);
	int direction = 0;
	bool flag = true;
	while ((start.x != currentPoint.x) || (start.y != currentPoint.y)) {
		if (flag) {
			currentPoint.x = start.x;
			currentPoint.y = start.y;
			flag = false;
		}
		InsertArray(point_set, currentPoint);
		for (int k = 0; k < 4; k++) {
			if ((k + direction + 3) % 4 == 0) {
				int pixel_value = image_data[currentPoint.x + (currentPoint.y - 1) * ws];
				if (pixel_value == 255) {
					direction = 0;
					currentPoint.y--;
					break;
				}
			}
			else if ((k + direction + 3) % 4 == 1) {
				int pixel_value = image_data[currentPoint.x + 1 + currentPoint.y * ws];
				if (pixel_value == 255) {
					direction = 1;
					currentPoint.x++;
					break;
				}
			}
			else if ((k + direction + 3) % 4 == 2) {
				int pixel_value = image_data[currentPoint.x + (currentPoint.y + 1) * ws];
				if (pixel_value == 255) {
					direction = 2;
					currentPoint.y++;
					break;
				}
			}
			else {
				int pixel_value = image_data[currentPoint.x - 1 + currentPoint.y * ws];
				if (pixel_value == 255) {
					direction = 3;
					currentPoint.x--;
					break;
				}
			}
		}
	}

	return EOK;
}


int FillInside(const IplImage* image, Array point_set) {
	int ws = image->widthStep;
	int h = image->height;
	uchar* image_data = (uchar*)image->imageData;

	int y_min = h;
	int y_max = 0;
	for (int i = 0; i < point_set.used; i++) {
		if (point_set.array[i].y < y_min)
			y_min = point_set.array[i].y;
		if (point_set.array[i].y > y_max)
			y_max = point_set.array[i].y;
	}

	for (int j = y_min; j <= y_max; j++) {
		int x_min = ws;
		int x_max = 0;
		for (int i = 0; i < point_set.used; i++) {
			if (point_set.array[i].y == j) {
				if (point_set.array[i].x < x_min)
					x_min = point_set.array[i].x;
				if (point_set.array[i].x > x_max)
					x_max = point_set.array[i].x;
			}
		}
		for (int k = x_min; k <= x_max; k++) {
			image_data[k + j * ws] = 0;
		}
	}

	return EOK;
}


int FindCenter_with_Centroid(Array point_set, CvPoint2D32f* centroidCenter) {
	int sumX = 0;
	int sumY = 0;
	for (int i = 0; i < point_set.used; i++) {
		sumX += point_set.array[i].x;
		sumY += point_set.array[i].y;
	}
	centroidCenter->x = (float)sumX / (float)point_set.used;
	centroidCenter->y = (float)sumY / (float)point_set.used;

	return EOK;
}


int FindCenter_with_Moments(const IplImage* image, Array point_set, CvPoint2D32f* momentCenter) {
	double m00 = 0;
	double m10 = 0;
	double m01 = 0;

	int ws = image->widthStep;
	int h = image->height;
	uchar* image_data = (uchar*)image->imageData;

	int y_min = h;
	int y_max = 0;
	for (int i = 0; i < point_set.used; i++) {
		if (point_set.array[i].y < y_min)
			y_min = point_set.array[i].y;
		if (point_set.array[i].y > y_max)
			y_max = point_set.array[i].y;
	}

	for (int j = y_min; j <= y_max; j++) {
		int x_min = ws;
		int x_max = 0;
		for (int i = 0; i < point_set.used; i++) {
			if (point_set.array[i].y == j) {
				if (point_set.array[i].x < x_min)
					x_min = point_set.array[i].x;
				if (point_set.array[i].x > x_max)
					x_max = point_set.array[i].x;
			}
		}
		for (int k = x_min; k <= x_max; k++) {
			double bij = (double)image_data[k + j * ws] / 255.0;
			m00 += bij;
			m10 += (double)k * bij;
			m01 += (double)j * bij;
		}
	}

	momentCenter->x = m10 / m00;
	momentCenter->y = m01 / m00;
	
	return EOK;
}


int RemoveSmallObjectContours(const IplImage* frame, const int point_num, CvPoint start, Array* point_set) {
	ERROR e = FindStart(frame, &start);
	if (ERREVAL(e)) {
		return EINVALID;
	}

	//FindBorder(image, start, &point_set[point_num]);

	FindContour(frame, start, &point_set[point_num], cvPoint(NULL, NULL), cvPoint(NULL, NULL));
	if (point_set[point_num].used < 10) {
		FillInside(frame, point_set[point_num]);
		InitArray(&point_set[point_num], 1);
		ERROR err = RemoveSmallObjectContours(frame, point_num, start, point_set);
		if (ERREVAL(err)) {
			return EINVALID;
		}
	}

	return EOK;
}


int FindAllCenters(IplImage* image, CvPoint start, Array* point_set, CvPoint2D32f* centers) {
	for (int point_num = 0; point_num < TOTAL_POINTS; point_num++) {
		InitArray(&point_set[point_num], 1);
		
		ERROR e = RemoveSmallObjectContours(image, point_num, start, point_set);
		if (ERREVAL(e)) {
			return EINVALID;
		}

		//FindCenter_with_Centroid(point_set[point_num], &centers[point_num]);
		//printf("Centroid center: x=%f, y=%f\n", centers[point_num].x, centers[point_num].y);
		FindCenter_with_Moments(image, point_set[point_num], &centers[point_num]);
		//printf("Moment center:\t x=%f, y=%f\n\n", centers[point_num].x, centers[point_num].y);
		FillInside(image, point_set[point_num]);
	}

	return EOK;
}


int RotationalTransformation(CvPoint2D32f point, CvPoint2D32f* convertedPoint, float theta) {
	float R11 = cos(theta);
	float R12 = -sin(theta);
	float R21 = -R12;
	float R22 = R11;

	convertedPoint->x = R11 * point.x + R21 * point.y;
	convertedPoint->y = R12 * point.x + R22 * point.y;

	return EOK;
}


int ChoosePoints3678(CvPoint2D32f* centers, CvPoint2D32f* points3678) {
	// Find geometrical center of the points:
	float sumX = 0;
	float sumY = 0;
	for (int i = 0; i < TOTAL_POINTS; i++) {
		sumX += centers[i].x;
		sumY += centers[i].y;
	}
	CvPoint2D32f geometrical_center = cvPoint2D32f(sumX / (float)TOTAL_POINTS, sumY / (float)TOTAL_POINTS);

	// Find 3rd point as the closest to the center:
	float distances[8];
	float min_distance = LONG_MAX;
	for (int i = 0; i < TOTAL_POINTS; i++) {
		distances[i] = sqrt(pow((geometrical_center.x - centers[i].x), 2) + pow((geometrical_center.y - centers[i].y), 2));
		if (distances[i] < min_distance) {
			points3678[0] = centers[i];
			min_distance = distances[i];
		}
	}

	// Make new coordinate system  on the line between the center point and the 3rd point and convert the point coordinates:
	float theta = atan2(geometrical_center.y - points3678[0].y, geometrical_center.x - points3678[0].x);
	CvPoint2D32f converted_points[TOTAL_POINTS];
	CvPoint2D32f translated_points[TOTAL_POINTS];
	for (int i = 0; i < TOTAL_POINTS; i++) {
		translated_points[i].x = centers[i].x - points3678[0].x; //Translation
		translated_points[i].y = centers[i].y - points3678[0].y;
		RotationalTransformation(translated_points[i], &converted_points[i], theta); //Rotation
	}

	// Find 3 farthest points from the new origo:
	int indicies[3] = { -1 };
	float max_distances[3] = { 0 };
	for (int i = 0; i < TOTAL_POINTS; i++) {
		if (distances[i] > max_distances[0])
		{
			max_distances[2] = max_distances[1];
			max_distances[1] = max_distances[0];
			max_distances[0] = distances[i];
			indicies[2] = indicies[1];
			indicies[1] = indicies[0];
			indicies[0] = i;
		}

		else if (distances[i] > max_distances[1])
		{
			max_distances[2] = max_distances[1];
			max_distances[1] = distances[i];
			indicies[2] = indicies[1];
			indicies[1] = i;
		}

		else if (distances[i] > max_distances[2]) {
			max_distances[2] = distances[i];
			indicies[2] = i;
		}
	}


	//Calculate their angle and match with the right points:
	float angles[3];
	float min_angle = LONG_MAX;
	float max_angle = LONG_MIN;
	float angle_from_zero = LONG_MAX;
	for (int i = 0; i < 3; i++) {
		angles[i] = atan2(converted_points[indicies[i]].y, converted_points[indicies[i]].x);
		if (angles[i] > max_angle) {
			max_angle = angles[i];
			points3678[1] = centers[indicies[i]];
		}
		if (abs(angles[i]) < angle_from_zero) {
			angle_from_zero = abs(angles[i]);
			points3678[2] = centers[indicies[i]];
		}
		if (angles[i] < min_angle) {
			min_angle = angles[i];
			points3678[3] = centers[indicies[i]];
		}
	}

	return EOK;
}