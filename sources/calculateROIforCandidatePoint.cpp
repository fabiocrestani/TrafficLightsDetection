//
// calculateROIforCandidatePoint.cpp
//

#include <opencv2/opencv.hpp>
#include "configs.h"
using namespace cv;

Rect calculateROIforCandidatePoint(myPoints point, Size imageSize) {
    
    int x1, x2, y1, y2;
    double width, height;
    
    x1 = point.boundingBoxP1.x - 20;
    y1 = point.boundingBoxP1.y - 20;
    x2 = point.boundingBoxP2.x + 20;
    y2 = point.boundingBoxP2.y + 20;
    
    // Check if the ROI respects the image boundaries.
    x1 = MIN(x1, x2);
    x1 = (x1 < 0 ? 0 : x1);
    y1 = MIN(y1, y2);
    y1 = (y1 < 0 ? 0 : y1);
    width = abs(x1-x2);
    width = ( (x1+width) >=  imageSize.width ? (imageSize.width-x1) : width);
    height = abs(y1-y2);
    height = ( (y1+height) >=  imageSize.height ? (imageSize.height-y1) : height);
    
    return Rect(x1, y1, width, height);
    
}
