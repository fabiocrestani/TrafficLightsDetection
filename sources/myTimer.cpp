#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include <sys/time.h>                // for gettimeofday()
using namespace std;

#include "configs.h"

#include "myTimer.h"
#include "myTimerList.h"


/*

*/
vector<myTimerList> myTimer::timerList;

/*
	myTimer (constructor)

*/	
myTimer::myTimer() {
	elapsedTime = 0;
}


/*
	startTimer

	Use this function to start a timer.
*/

void myTimer::startTimer() {
	#ifdef TIMER_IS_ON
		gettimeofday(&t1, NULL);
	#endif
}


/*
	startTimer

	Use this function to start a timer.
	Overloaded method to get a String argument.

	Input: String l is a description of what you are timing
*/

void myTimer::startTimer(String l) {
	#ifdef TIMER_IS_ON
		label = l;
		gettimeofday(&t1, NULL);
	#endif
}


/*
	stopTimer

	Use this function to stop a timer.
	User comuteTime to get the elapsed time.
*/
void myTimer::stopTimer() {
	#ifdef TIMER_IS_ON
		gettimeofday(&t2, NULL);
		computeTime();
	#endif
}


/*
	computeTime

  	Computes the elapsed time.

	Output: returns a double with the elapsed time in miliseconds.
*/

double myTimer::computeTime() {
	#ifdef TIMER_IS_ON
		//sec to ms
		elapsedTime  = (t2.tv_sec - t1.tv_sec) * 1000.0; 

		//us to ms
	  	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	  	#ifdef PRINT_TIMER_TERMINAL
	  		cout << elapsedTime << "," << label << endl;
	  	#endif

	  	myTimerList timerResult(elapsedTime, label);
	  	timerList.push_back(timerResult);

		return elapsedTime;
	#else
		return 0;
	#endif
}


/*
	finishTimers

	Computes all the average time for every timer and add it to the text file
*/
void myTimer::finishTimers() {
	#ifdef TIMER_IS_ON
		ofstream timerFile;
		timerFile.open("timerResults.csv");

		for (int i = 0; i < timerList.size(); i++) {
			timerFile << timerList[i].getElapsedTime() << "," << 
			             timerList[i].getLabel() << endl; 
		}


		cout << endl << "Timer results saved to file " << TIMER_FILE_NAME << 
				endl;

		timerFile.close();
	#endif
}




/* ------------------------------------------------------------------------- */
/* old C version: */
/* ------------------------------------------------------------------------- */

/*
	startTimer

	Use this function to start a timer.


void _startTimer(myTimerHandler *timerObj) {

	gettimeofday(&(timerObj->t1), NULL);

}

 
	stopTimer

	Use this function to stop a timer.
	User comuteTime to get the elapsed time.


void _stopTimer(myTimerHandler *timerObj) {

	gettimeofday(&(timerObj->t2), NULL);

}


	computeTime

  Computes the elapsed time.

	Output: returns a double with the elapsed time in miliseconds.


double _computeTime(myTimerHandler timerObj, String label, 
	                  std::ofstream& file) {

	double elapsedTime;

	//sec to ms
	elapsedTime  = ((timerObj.t2).tv_sec - (timerObj.t1).tv_sec) * 1000.0; 

	//us to ms
  elapsedTime += ((timerObj.t2).tv_usec - (timerObj.t1).tv_usec) / 1000.0;

  // Data exported in CSV format
  file << elapsedTime << "," << label << endl;

	return elapsedTime;
}
*/

