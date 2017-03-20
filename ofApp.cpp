
//Example of using the Easycontroller.
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
 
ctrl.label("s1","master");
ctrl.label("s4","bright");
ctrl.label("s6","points");
ctrl.label("p1","on/off");
ctrl.label("p2b","start");
     
}


//--------------------------------------------------------------
void ofApp::update(){
    }

//--------------------------------------------------------------
void ofApp::draw(){
    int value1=  ctrl.rec("s1");//value from knob 1.
    float value2= ctrl.rec("s1",0.1,1.1);//value from knob 2 with remapped to from 0-127 to 0.1-1.1
    float value2b=ctrl.rec("s2b",-0.1,1.1);//value from knob 2b witb 0.1-1.1
    int valuep1=ctrl.rec("p1");//value from button p1, you can choose from p1-p8 and p1b-p8b


    ofSetColor(0);
    ofDrawBitmapString(ofGetFrameRate(),20,20);
    ofDrawBitmapString("-----Change in Easycontroller-----",40,70);
    ofDrawBitmapString("Slider 1 (s1):             "+ ofToString(value1),40,90);
    ofDrawBitmapString("Slider 1 re-mapped (s1):   "+ ofToString(value2),40,110);
    ofDrawBitmapString("Slider 2 from set b (s2b): "+ ofToString(value2b),40,130);
    ofDrawBitmapString("Pad number 1 (p1):         "+ ofToString(valuep1),40,150);
    ofDrawBitmapString("----------------------------------",40,170);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==48)
    {
ctrl.~escon();
std::exit(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
