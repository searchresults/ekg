/*
 *  MouseCircleFollow.h
 *  emptyExample
 *
 *  Created by Dan Haeg on 10/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once
#ifndef _MOUSE_C_FOLLOW  // dh
#define _MOUSE_C_FOLLOW  // dh
#define numOfCircles 1650  // dh

#include "ofMain.h"

class MouseCircleFollow : public ofBaseApp{
	
public:
	void setup();
	void draw();
	void update();
	
	//float xPos[numOfCircles];
	int yPos[numOfCircles];
	int startTime, currentTime;
	int ii;
	int blueRed;
	int blueGreen;
	int blueBlue;
	int frameTime;
	ofTrueTypeFont  franklinBook14;
	ofTrueTypeFont	verdana14;
	ofTrueTypeFont	verdana30;
	ofTrueTypeFont  franklinBook14A;
	ofTrueTypeFont	verdana14A;
	
	
//	float yPos[numOfCircles];
//	float dist(int startX, int startY, int endX, int endY);
//	float createRandomizedNewPos(float in, float mouse);
//	float max_distance;
};
#endif