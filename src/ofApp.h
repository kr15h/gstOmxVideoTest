#pragma once

#include "ofMain.h"

#ifdef TARGET_RASPBERRY_PI
#include "ofxOMXPlayer.h"
#endif

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		ofVideoPlayer video;
	
#ifdef TARGET_RASPBERRY_PI
		ofxOMXPlayer omxPlayer;
#endif
};
