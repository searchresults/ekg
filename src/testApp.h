#pragma once
#ifndef _MOUSE_C_FOLLOW  // dh
#define _MOUSE_C_FOLLOW  // dh
#define numOfCircles 20  // dh

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	

	class MouseCircleFollow : public ofBaseApp{
	public:
		void setup();
		void draw();
		void update();
		
		float xPos[numOfCircles];
		float yPos[numOfCircles];
		float dist(int startX, int startY, int endX, int endY);
		float createRandomizedNewPos(float in, float mouse);
		float max_distance;
	};
#endif
	
	
	
	
	
	
	
	
	
	
		
};
