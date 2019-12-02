#include "core_imgproc.h"

typedef struct {
	float p0;
	float p1;
	float p2;
	float q0;
	float q1;
	float q2;
} Affine;

typedef struct {
	float x;
	float y;
	float z;
} Euler;

#define M_PI acos(-1.0)

int PixelToCameraCoordinate(const CvPoint2D32f P[4], CvPoint2D32f C[4], const CvMat* K);
int GetP4PAbidi(const CvMat* S, const CvPoint2D32f P[4], CvPoint3D32f out[4], float* confidence);
int GetDistancesMatrix(CvMat* S);
int CalculateRotationMatrix(const CvPoint3D32f abidi[4], CvMat* R);
int RotationMatrixToEuler(const CvMat* R, Euler* angles);
int RadiansToDegreesEulers(const Euler angles_rad, Euler* angles_deg);
int CalculateAffineTransform(CvPoint points_L[], CvPoint points_R[], Affine* ret);
int ApplyAffineTransform(CvPoint2D32f pl, Affine T, CvPoint2D32f* pr);