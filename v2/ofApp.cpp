
//Example of using the Easycontroller.
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //some labeling
    ctrl.label("s1a","OF1");
    ctrl.label("s3a","OF2");
    ctrl.label("s6a","points");
    ctrl.label("p1a","on/off");
    ctrl.label("p2b","start");
    ctrl.label("p4b","pre-2");
   
    //some initials
    ctrl.all_s(64); //put all knobs (s1-s8,s1b-s8b) on 64.  (doesn't effect on maste slides s0 and s0b)
    ctrl.all_p(0); // turn off all pads.
    ctrl.call_preset(1);//presets are only for knobs.
    playaround=1;
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
    //Manipulating pad p4b to trigger preset 2 if the preset was defined, IN THE UPDATE.
    ctrl.set_to_preset("p4b",2);
    
    
    //Moving s3 opposite to moving s1.
    //ctrl.snd("s3",127-ctrl.rec("s1"));
    
    //playing with the pads
    if(playaround%10==0)
    ctrl.snd(playaround%9+100,0);
    playaround++;
    if(playaround%10-1==0)
    ctrl.snd(playaround%9+100,1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //recieving and re-mapping
    int   value1=  ctrl.rec("s1a");//value from knob 1.
    float value2= ctrl.rec("s1a",0.1,1.1);//value from knob 2 with remapped to from 0-127 to 0.1-1.1
    float value2b=ctrl.rec("s2b",-0.5,5.0);//value from knob 2b witb 0.1-1.1
    int   valuep1=ctrl.rec("p1a");//value from button p1, you can choose from p1-p8 and p1b-p8b
    
    

    ofSetColor(0);
    ofDrawBitmapString(ofGetFrameRate(),20,20);
    ofDrawBitmapString("-----Change in Easycontroller-----",40,70);
    ofDrawBitmapString("Slider 1 (s1a):             "+ ofToString(value1),40,90);
    ofDrawBitmapString("Slider 1 re-mapped (s1a):   "+ ofToString(value2),40,110);
    ofDrawBitmapString("Slider 2 from set b (s2b): "+ ofToString(value2b),40,130);
    ofDrawBitmapString("Pad number 1 (p1a):         "+ ofToString(valuep1),40,150);
    ofDrawBitmapString("----------------------------------",40,170);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==48)
    {
ctrl.~escon();//also stopping communication, and automatic when exit, use activate(0 or 1) function to         manualy stop or start communication
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
