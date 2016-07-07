/*! \file prepareFrame.h
    \brief prepareFrame()

*/
#include <stdio.h>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include "configs.h"

using namespace cv;

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
){
    
    Size imgSize;
    Rect upperROI;
    
    if (crop) {
        imgSize = image.size();

        // Assume the upper (heightFactor) of the image as the area of interest.
        upperROI = Rect(0, 0, imgSize.width, imgSize.height*heightFactor);

        // Extract the region of interest from the input image.
        image(upperROI).copyTo(img);

    } else {
        image.copyTo(img);
    }
    
    // Apply blur to the input image.
    blur(img, img, Size(BLUR_SIZE,BLUR_SIZE), Point(-1,-1));

    // Increase image brightness. Attenuate the blue color scale.
    img *= 1.2;
    img += Scalar(50, 0, 0);

    // Convert the processed image to grayscale and HSV.
    cvtColor(img, imgGray, CV_BGR2GRAY);
    cvtColor(img, imgHSV, CV_BGR2HSV);
}
