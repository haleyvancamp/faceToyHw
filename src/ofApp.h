#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber cam;
    ofxCv::ObjectFinder finder;
    //ofxCv::ObjectFinder finder2;
    ofImage monkey;
    ofImage banana;
    ofImage banana2;
    //vector<ofImage> bananas;
};
