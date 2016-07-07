/*! \file prepareFrame.h
    \brief prepareFrame()

*/

#pragma once

///
///	First step in the image processing. Crops the upper part of the image, 
/// applies a blue filter, increases the contrast, creates a copy of this result
/// in grayscale and another copy converted to HSV colorspace.
///
void prepareFrame(
	Mat &image,   		 /**< [in] Input image. */
    Mat &img,     		 /**< [out] Processed image. */
    Mat &imgGray, 		 /**< [out] Processed and grayscale-converted image. */
	Mat &imgHSV,  		 /**< [out] Processed and HSV-converted image. */
    double heightFactor, /**< [in] How much of the image will be cropped. */
	bool crop 			 /**< [in] If true, the image will be cropped. */
);
