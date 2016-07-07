/*! \file configs.h
    \brief All the definitions and parameters.
    
    	This file has all the configurations, definitions and static parameters
    which are used in many of the functions of the project. It has also the 
    definition of the myPoints structure, which stores all the relevant data 
    about every blob detected (e.g. position, size, area, color, orientation).
*/

#include <opencv2/opencv.hpp>

using namespace cv;

#define CURRENT_DATASET "datasets/SanFrancisco"
#define VERSION_ID "1.0"
#define BLUR_SIZE 2 //2
#define MORPH_SIZE 10

#define SHOW_ORIGINAL_IMAGE 1
#define SHOW_RESULT_OVERLAYED 1
//#define DEBUG_WINDOWS 1 // enables all imshow()
//#define DEBUG_WINDOWS_BLOB_DETECTOR 1
//#define WAIT_FOR_USER 1   // enables user keyboard inputs

#define RED_FLAG 0
#define YEL_FLAG 1
#define GRE_FLAG 2

// Color segmentation
#define RED_L_LOW  0
#define RED_L_HIGH 23
#define RED_H_LOW  160
#define RED_H_HIGH 179
#define GRE_LOW    40
#define GRE_HIGH   95
#define YEL_LOW    24
#define YEL_HIGH   40

// Blob detection
#define RESIZE_BLOB_DETECTION 1
#define BLOB_MIN_AREA 2
#define BLOB_MAX_AREA 200
//#define BLOB_MIN_AREA 35
//#define BLOB_MAX_AREA 400

#define RESIZE_SCALE 0.5
#define RESIZE_MULTIPLIER 2

// ROI extraction
#define ROI_BB_SIZE_MULTIPLIER 5
#define ROI_MULTIPLIER         3

// Orientation
#define NO_ORIENTATION 0
#define VERTICAL       1
#define HORIZONTAL     2

// Histogram
//#define SHOW_HISTOGRAM 1
#define HISTOGRAM_THRESHOLD   0.5
#define HISTOGRAM_ROI_MAX_BIN 50

#define APPLY_SOBEL_ROI 1

// Tracker
#define IMAGE_HEIGHT_FACTOR 0.5
#define TRACKED_POINT_HIT_UPPER_LIMIT 20
#define TRACKED_POINT_DISTANCE_THRESHOLD 50
#define TRACKED_POINT_CLEAR_THRESHOLD 0
#define TRACKER_FRAME_LIMIT 3
#define SEMAPHORE_DRAW_THRESHOLD 10

// Timer
#define TIMER_FILE_NAME "timerResultsARM.csv"
#define TIMER_IS_ON 1

/*! \struct myPoints
	\brief Stores all the relevant data about every blob.
	
	Stores all the relevant data about every blob detected (e.g. position, size,
	area, color, orientation).
*/
typedef struct {
	float x;
	float y;
	float area;
	int color;
	int frameId;
	int orientation;
    
    int roiHits;

	bool tracking_point;

	// For orientation calculation
	float horizontalGreenRatio;
	float verticalGreenRatio;
	float horizontalYellowRatio;
	float verticalYellowRatio;
	float horizontalRedRatio;
	float verticalRedRatio;

	// Candidate bouding boxes points
	Point greenVerticalBBP1;
	Point greenVerticalBBP2;
	Point greenHorizontalBBP1;
	Point greenHorizontalBBP2;

	Point yellowVerticalBBP1;
	Point yellowVerticalBBP2;
	Point yellowHorizontalBBP1;
	Point yellowHorizontalBBP2;

	Point redVerticalBBP1;
	Point redVerticalBBP2;
	Point redHorizontalBBP1;
	Point redHorizontalBBP2;

	// Final bounding boxes points
	Point boundingBoxP1;
	Point boundingBoxP2;

	Scalar boundingBoxColor;

} myPoints;
