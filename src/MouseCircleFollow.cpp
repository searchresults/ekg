#include "MouseCircleFollow.h"

void MouseCircleFollow::setup(){
	ofSetWindowShape(1650,700);
	ofBackground(245,245,245);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	
	int i;
	int ii = 0;
	int frameTime = 0;  // this is the minimum number of milliseconds to wait when updating the array
	
	ofTrueTypeFont::setGlobalDpi(72);
	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
	
	verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
	
	verdana14A.loadFont("frabk.ttf", 14, false);
	verdana14A.setLineHeight(18.0f);
	verdana14A.setLetterSpacing(1.037);
	
	franklinBook14.loadFont("frabk.ttf", 14);
	franklinBook14.setLineHeight(18.0f);
	franklinBook14.setLetterSpacing(1.037);
	
	franklinBook14A.loadFont("frabk.ttf", 14, false);
	franklinBook14A.setLineHeight(18.0f);
	franklinBook14A.setLetterSpacing(1.037);
	

	int currentTime = ofGetElapsedTimeMillis();
	int startTime = ofGetElapsedTimeMillis();
	for(i = 0; i<numOfCircles; i++) { yPos[i] = (ofGetHeight() /2); }
}



void MouseCircleFollow::update(){
	float	modifier;
	currentTime = ofGetElapsedTimeMillis();
	
	if ((currentTime - startTime) > frameTime) {	
		if (ii < numOfCircles) {
		startTime = ofGetElapsedTimeMillis();
		yPos[ii] = mouseY;
		ii++;
		}
		else { 
			ii = 0; 
			startTime = ofGetElapsedTimeMillis(); 
		}
	}
 }  // end of mouseCircleFollow



void MouseCircleFollow::draw(){
	float trans;
	int transInt;
	int blueRed = 108;
	int blueGreen = 203;
	int blueBlue = 218;
	int orangeRed = 255;
	int orangeGreen = 110;
	int orangeBlue = 25;
	int gridWhite = 235;
	
	//  draw grid
	ofDisableSmoothing();
	ofSetLineWidth(1);
	ofSetColor(gridWhite, gridWhite, gridWhite);
	for (int YY= 0;  YY < (ofGetScreenHeight()) ; YY += 50 ) { ofLine (0, YY, ofGetScreenWidth() , YY); }   
	for (int XX = 0; XX < (ofGetScreenWidth()) ; XX += 50 ) { ofLine (XX, 0, XX, ofGetScreenHeight() ); }
	ofSetLineWidth(2);
	ofEnableSmoothing();
	
	// draw text
	ofSetColor(orangeRed, orangeGreen, orangeBlue, 222);
	verdana30.drawString("EKG Measurements", 20, ofGetHeight()-20);
	
	// draw line
	for(int jj = 0; jj<numOfCircles; jj ++) {  
		
		if ( ((jj-ii) > 0) && ( (jj-ii) <= 255) ) { 
			trans = ceil ((250 * ((jj-ii)/200)) );
			transInt = int(trans);
			ofSetColor(blueRed,blueGreen,blueBlue, 255 * (float(jj)/float(numOfCircles)) );    //having BIG problems with the alpha part...usually won't accept transInt variable, will behave strangely with simple integers too (like "10"!)
		
			ofLine ((jj-1), yPos[jj-1], (jj), yPos[jj] ); 
		}
		
		else if ( ((jj-ii) >= 0) && ( (jj-ii) <= 50) ) { }
		
		else { 
			ofSetColor(blueRed,blueGreen,blueBlue, 255); 
			ofLine ((jj-1), yPos[jj-1], (jj), yPos[jj] );
		}
	}
}
