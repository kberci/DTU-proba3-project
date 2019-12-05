#include "core_imgproc.h"

typedef struct {
	CvPoint* array;
	size_t used;
	size_t size;
} Array;

int InitArray(Array* a, size_t initialSize);
int InsertArray(Array* a, CvPoint element);
int FreeArray(Array* a);
int FindStart(const IplImage* image, CvPoint* start);
int FindBorder(const IplImage* image, CvPoint start, Array* point_set);
int FillInside(const IplImage* image, Array point_set);
int FindCenter_with_Centroid(Array point_set, CvPoint2D32f* center);
int FindAllCenters(IplImage* image, CvPoint start, Array* point_set, CvPoint2D32f* centers);
int RotationalTransformation(CvPoint point, CvPoint* convertedPoint, float theta);
int ChoosePoints3678(CvPoint2D32f* centers, CvPoint2D32f* points3678);
int FindCenter_with_Moments(const IplImage* image, Array point_set, CvPoint2D32f* momentCenter);
int FindContour(const IplImage* frame, CvPoint start, Array* point_set, CvPoint from, CvPoint p);