#include "core_imgproc.h"


int CreateBinary(const IplImage* frame, IplImage* binary, const int threshold) {
	if (threshold > 255 || threshold < 0) return EARGS;
	if (frame->nChannels != 1) return EARGS;
	if (binary->height != frame->height || binary->width != frame->width) return ESHAPE;

	uchar* frame_data = (uchar*)frame->imageData;
	uchar* binary_data = (uchar*)binary->imageData;

	for (int j = 0; j < binary->height; j++) {
		for (int i = 0; i < binary->width; i++) {
			int pixel_value = frame_data[i + j * frame->widthStep];
			if (pixel_value >= threshold) {
				binary_data[i + j * binary->widthStep] = 255;
			}
			else {
				binary_data[i + j * binary->widthStep] = 0;
			}
		}
	}

	return EOK;
}


int UndistortImage(const IplImage* distorted, IplImage* undistorted, const CvMat* K) {
	uchar* data_distorted   = (uchar*)distorted->imageData;
	uchar* data_undistorted = (uchar*)undistorted->imageData;

	float fx = CV_MAT_ELEM(*K, float, 0, 0);
	float fy = CV_MAT_ELEM(*K, float, 1, 1);
	float s  = CV_MAT_ELEM(*K, float, 0, 1);
	float cx = CV_MAT_ELEM(*K, float, 0, 2);
	float cy = CV_MAT_ELEM(*K, float, 1, 2);
	
	float k1 = -0.2381;
	float k2 = 0.3543;

	for (int j = 0; j < undistorted->height; j++) {
		for (int i = 0; i < undistorted->width; i++) {
			// apply the inverse of K to pixel coordinates
			float x = (i * fy - j * s - cx * fy + cy * s) / (fx * fy);
			float y = (j - cy) / fy;
			float r = pow(x, 2) + pow(y, 2);

			// correct for radial distortion
			float xp = x * (1 + k1 * pow(r, 2) + k2 * pow(r, 4));
			float yp = y * (1 + k1 * pow(r, 2) + k2 * pow(r, 4));

			// apply K again to get back to pixel coords
			float xpp = cx + xp * fx + yp * s;
			float ypp = cy + yp * fy;
			CvPoint2D32f distorted_pixel_coords = cvPoint2D32f(xpp, ypp);

			int indexO = i + j * undistorted->widthStep;

			data_undistorted[indexO] = InterpolatePixelValue(distorted, distorted_pixel_coords);
		}
	}

	return EOK;
}


int InterpolatePixelValue(IplImage* image, CvPoint2D32f p) {
	if (p.x >= 0 && p.x < image->width - 1 && p.y >= 0 && p.y < image->height - 1) {
		uchar* data = (uchar*)image->imageData;

		float x1 = floor(p.x);
		float x2 = ceil(p.x);
		float y1 = floor(p.y);
		float y2 = ceil(p.y);

		if (x1 == x2) x2 += 1;
		if (y1 == y2) y2 += 1;

		int ind1 = (int)(x1 + y1 * image->widthStep);
		int ind2 = (int)(x1 + y2 * image->widthStep);
		int ind3 = (int)(x2 + y1 * image->widthStep);
		int ind4 = (int)(x2 + y2 * image->widthStep);

		float a = ((x2 - p.x) / (x2 - x1)) * data[ind1] + ((p.x - x1) / (x2 - x1)) * data[ind3];
		float b = ((x2 - p.x) / (x2 - x1)) * data[ind2] + ((p.x - x1) / (x2 - x1)) * data[ind4];
		float ret = ((y2 - p.y) / (y2 - y1)) * a + ((p.y - y1) / (y2 - y1)) * b;

		return (int)ret;
	}

	return 0;
}


int GetCameraIntrinsicMatrix(CvMat* K) {
	float fx = 2.8339e3;
	float fy = 2.8277e3;
	float cx = 1.0500e3;
	float cy = 869.6825;
	float s = 0;

	CV_MAT_ELEM(*K, float, 0, 0) = fx;
	CV_MAT_ELEM(*K, float, 1, 1) = fy;
	CV_MAT_ELEM(*K, float, 0, 1) = s;
	CV_MAT_ELEM(*K, float, 0, 2) = cx;
	CV_MAT_ELEM(*K, float, 1, 2) = cy;

	return EOK;
}


//int GetPixelValue(const IplImage* frame, const CvPoint at, Pixel* out) {
//	// CvPoint at -> (column, row)
//
//	int step = frame->widthStep;
//	int channels = frame->nChannels;
//
//	*out = pixel(0, channels);
//	uchar* data = (uchar*)frame->imageData;
//
//	// for 3-channel (RGB) image: blue->k=0, green->k=1, red->k=2
//	for (int k = 0; k < channels; k++) {
//		int pixel_value = data[at.x * channels + at.y * step + k];
//		out->val.val[k] = pixel_value;
//	}
//
//	return EOK;
//}
//
//int SetPixelValue(const IplImage* frame, const CvPoint at, const Pixel pix) {
//
//	int step = frame->widthStep;
//	int channels = frame->nChannels;
//	uchar* data = (uchar*)frame->imageData;
//
//	if (channels > pix.count) return ENOTOK;
//
//	// for 3-channel (RGB) image: blue->k=0, green->k=1, red->k=2
//	for (int k = 0; k < channels; k++) {
//		data[at.x * channels + at.y * step + k] = (int)pix.val.val[k];
//	}
//
//	return EOK;
//}
//
//int SetImagePixels(const Pixel color, IplImage* out) {
//	uchar* data = (uchar*)out->imageData;
//
//	for (int j = 0; j < out->height; j++) {
//		for (int i = 0; i < out->width; i++) {
//			SetPixelValue(out, cvPoint(i, j), color);
//
//
//			for (int k = 0; k < out->nChannels; k++) {
//				data[i * out->nChannels + j * out->widthStep + k] = color.val.val[k];
//			}
//		}
//	}
//
//	return EOK;
//}