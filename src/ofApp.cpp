#include "ofApp.h"

void ofApp::setup(){
	video.load("beeple720p.mp4");
	video.setLoopState(ofLoopType::OF_LOOP_NORMAL);
	video.play();
	
#ifdef TARGET_RASPBERRY_PI
	ofxOMXPlayerSettings settings;
	settings.videoPath = "beeple720p.mp4";
	settings.useHDMIForAudio = true;
	settings.enableTexture = true;
	settings.enableLooping = true;
	settings.enableAudio = true;
	omxPlayer.setup(settings);
	ofSetFullscreen(true);
#endif
}

void ofApp::update(){
	video.update();
}

void ofApp::draw(){
	video.draw(0, 0, (float)ofGetWidth() / 2.0f, ofGetHeight());
	ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate()), 10, 20);
	ofDrawBitmapStringHighlight("Default video player", 10, 50);
#ifdef TARGET_RASPBERRY_PI
	omxPlayer.draw((float)ofGetWidth() / 2.0f, 0, (float)ofGetWidth() / 2.0f, ofGetHeight());
	ofDrawBitmapStringHighlight("OMX video player", ((float)ofGetWidth() / 2.0f) + 10, 50);
#else
	video.draw((float)ofGetWidth() / 2.0f, 0, (float)ofGetWidth() / 2.0f, ofGetHeight());
	ofDrawBitmapStringHighlight("Default video player", ((float)ofGetWidth() / 2.0f) + 10, 50);
#endif
}
