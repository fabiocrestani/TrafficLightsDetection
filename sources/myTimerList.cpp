#include <string>

#include <iostream>
using namespace std;

#include "myTimerList.h"

myTimerList::myTimerList() {

}


myTimerList::myTimerList(double e, string l){
	elapsedTime = e;
	label = l;
}

double myTimerList::getElapsedTime() {
	return elapsedTime;
}

string myTimerList::getLabel() {
	return label;
}