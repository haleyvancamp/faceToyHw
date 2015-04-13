#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    ofSetWindowShape(640, 480);
    finder.setup("haarcascade_frontalface_alt2.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    
    //finder2.setup("haarcascade_profileface.xml");
    //finder2.setPreset(ObjectFinder::Fast);
    //finder2.getTracker().setSmoothingRate(.3);
    cam.initGrabber(640, 480);
    monkey.loadImage("monkey.png");
    banana.loadImage("banana.png");
    banana2.loadImage("banana2.png");
    //bananas.
    ofEnableAlphaBlending();
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
        //finder2.update(cam);
    }
}

void ofApp::draw() {
    cam.draw(0, 0);
    
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        monkey.setAnchorPercent(.5, .5);
        float scaleAmount = 4. * object.width / monkey.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);
        monkey.draw(100, 0);
        
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
        
       //object = finder.getObjectSmoothed(i);
        banana.setAnchorPercent(.5, .5);
        scaleAmount = .7 * object.width / banana.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);
        banana.draw(700, 200);
        
        
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
        
        //object = finder.getObjectSmoothed(i);
        banana2.setAnchorPercent(.5, .5);
        scaleAmount = .7 * object.width / banana2.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);
        banana2.draw(-700, 200);
        
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
        
        
        
    }
    
    /*for(int i = 0; i < finder2.size(); i++) {
        ofRectangle object = finder2.getObjectSmoothed(i);
        banana.setAnchorPercent(.5, .5);
        float scaleAmount1 = .7 * object.width / banana.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        //ofRect(object.x, object.y, object.width, object.height);

        ofScale(scaleAmount1, scaleAmount1);
        banana.draw(700, 200);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder2.getLabel(i)), 0, 0);
        
        ofLine(ofVec2f(), toOf(finder2.getVelocity(i)) * 10);
        ofPopMatrix();
    }*/
    

}
