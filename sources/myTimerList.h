#pragma once

#include <string>
#include <iostream>
using namespace std;

class myTimerList {

public:
	myTimerList();
	myTimerList(double e, string l);
	
	double getElapsedTime();
	string getLabel();

private:
	double elapsedTime;
	string label;
};