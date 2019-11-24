#include "core_imgproc.h"

typedef struct {
	float p0;
	float p1;
	float p2;
	float q0;
	float q1;
	float q2;
} Affine;

int PixelToCameraCoordinate(const CvPoint2D32f P[4], CvPoint2D32f* C[4]);
int GetP4PAbidi(const CvMat* S, const CvPoint2D32f P[4], CvPoint3D32f out[4]);
int GetDistancesMatrix(CvMat* S);
int CalculateAffineTransform(CvPoint points_L[], CvPoint points_R[], Affine* ret);
int ApplyAffineTransform(CvPoint2D32f pl, Affine T, CvPoint2D32f* pr);