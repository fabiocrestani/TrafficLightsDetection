#pragma once

/*
void _startTimer(myTimerHandler *timerObj);

void _stopTimer(myTimerHandler *timerObj);

double _computeTime(myTimerHandler timerObj, String label, 
	                std::ofstream& file);
*/

#include "myTimerList.h"

/*
	class myTimer

	Usage:
		myTimer timer;
		timer.startTimer("name_of_a_particular_step");
			...
			particularStep();
			...
		timer.stopTimer();
	
		...

		timer.computeTime();
		timer.finishTimers();
*/

class myTimer {

private:
	struct timeval t1;
	struct timeval t2;
	double elapsedTime;
	string label;
	int timerId;
	int count;

	static vector<myTimerList> timerList;

public:
	myTimer();
	void startTimer();
	void startTimer(String l);
	void stopTimer();
	double computeTime();

	static void finishTimers();

};
