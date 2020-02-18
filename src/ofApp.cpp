#include "ofApp.h"

//face variables
ofCircle face;
ofCircle faceOutline;
int faceWidth = 180;
int faceHeight = 180;

int strokeThickness = 12;

int eyeDistanceX = 45;
int eyeDistanceY = 2;
int eyeSize = 12;

int eyebrowDistanceX = 33;
int eyebrowDistanceY = 32;
int eyebrowWidth = 30;
int eyebrowHeight = 12;

int mouthWidth = 30;

//controls
int slideNumber = 0;
float currentTime = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(135, 214, 235);
    drawFace(ofGetWidth()/2, ofGetHeight()/2);
    
    if (slideNumber == 0) {
        drawSadParts(ofGetWidth()/2, ofGetHeight()/2);
      
    }
    if (slideNumber == 1) {
        drawSurprisedParts(ofGetWidth()/2, ofGetHeight()/2);
   }
    if (slideNumber == 2) {
        drawAngryParts(ofGetWidth()/2, ofGetHeight()/2);
        
   }
    if (slideNumber == 3) {
        drawHappyParts(ofGetWidth()/2, ofGetHeight()/2);
    }
    
    if ((ofGetFrameNum() % 120) == 0) {
        if (slideNumber > 2){
            slideNumber = 0;
        } else {
            slideNumber++;
            //reset timer
            currentTime = ofGetFrameNum();
            ofLog(OF_LOG_NOTICE, ofToString(currentTime));
        }
    }
    
}
void ofApp::drawFace(int x, int y) {
    //outline of face
   ofSetColor(black);
   faceOutline.width = faceWidth + (2 * strokeThickness);
   faceOutline.height = faceHeight + (2 * strokeThickness);
   faceOutline.x =  x - (faceOutline.width/2);
   faceOutline.y = y - (faceOutline.height/2);
   ofDrawCircle(faceOutline, 60);
   
   //face
   ofSetColor(white);
   face.width = faceWidth;
   face.height = faceHeight;
   face.x = x - faceWidth/2;
   face.y = y - faceHeight/2;
   ofDrawRectRounded(face, 80);
   
   //left eye
   ofSetColor(black);
   ofDrawCircle(x - eyeDistanceX , y - eyeDistanceY , eyeSize);

   //right eye
   ofDrawCircle(x + eyeDistanceX , y - eyeDistanceY , eyeSize);
   
   
}
void ofApp::drawAngryParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
    ofPushMatrix();
    ofTranslate(leftEBX, leftEBY);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currentTime));
    ofDrawRectangle(-eyebrowDistanceX/2 - eyebrowWidth, - eyebrowDistanceY/2, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();

    //right eyebrow
    ofPushMatrix();
    ofTranslate(rightEBX, rightEBY);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currentTime) );
    ofDrawRectangle(eyebrowDistanceX/2, -eyebrowDistanceY/2, eyebrowWidth, eyebrowHeight);
     ofPopMatrix();
    
    //angry mouth
    ofDrawBezier(x - 10, y + 20 + (0.03 * (ofGetFrameNum() - currentTime)),
                 x - 10, y + 20 - (0.05 * (ofGetFrameNum() - currentTime)),
                 x + 10, y + 20 - (0.05 * (ofGetFrameNum() - currentTime)),
                 x + 10, y + 20 + (0.03 * (ofGetFrameNum() - currentTime))
                 );
}

void ofApp::drawSadParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
    ofPushMatrix();
    ofTranslate(leftEBX, leftEBY);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currentTime));
    ofDrawRectangle(-eyebrowDistanceX/2 - eyebrowWidth, - eyebrowDistanceY, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();

    //right eyebrow
    ofPushMatrix();
    ofTranslate(rightEBX, rightEBY);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currentTime) );
    ofDrawRectangle(eyebrowDistanceX/2, -eyebrowDistanceY, eyebrowWidth, eyebrowHeight);
     ofPopMatrix();
    

    //angry mouth
    ofDrawBezier(x - 10, y + 20 + 0.03 * (ofGetFrameNum() - currentTime),
                 x - 10, y + 20 - 0.05 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 - 0.05 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.03 * (ofGetFrameNum() - currentTime)
                 );
}

void ofApp::drawHappyParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
   ofDrawRectangle(x - eyebrowDistanceX - eyebrowWidth,  y - eyebrowDistanceY
                   - 0.05 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
   //right eyebrow
   ofDrawRectangle(x + eyebrowDistanceX, y - eyebrowDistanceY
                   - 0.05 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
    
    ofDrawBezier(x - 10, y + 20 + 0.05 * (ofGetFrameNum() - currentTime),
                 x - 10, y + 20 + 0.2 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.2 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.05 * (ofGetFrameNum() - currentTime)
                 );
}
void ofApp::drawSurprisedParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
   ofDrawRectangle(x - eyebrowDistanceX - eyebrowWidth,  y - eyebrowDistanceY
                   - 0.02 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
   //right eyebrow
   ofDrawRectangle(x + eyebrowDistanceX, y - eyebrowDistanceY
                   - 0.02 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
    
    ofDrawBezier(x - 10, y + 25 ,
                 x - 10, y + 25 - 0.1 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25 - 0.1 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25
                 );
    ofDrawBezier(x - 10, y + 25 ,
                 x - 10, y + 25 + 0.08 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25 + 0.08 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25
                 );
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
