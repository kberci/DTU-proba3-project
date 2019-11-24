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
int FindCenter(Array point_set, CvPoint* center);
int FindAllCenters(IplImage* image, CvPoint start, Array* point_set, CvPoint* centers);
int RotationalTransformation(CvPoint point, CvPoint* convertedPoint, float theta);
int ChoosePoints3678(CvPoint* centers, CvPoint* points3678);