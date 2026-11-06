#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1280, 847);
	bool loadingOk = imgSource.load("panda-roux.jpg");
	if (!loadingOk) {
		ofLogError() << "Image non trouvée";
	}
	imgResult.allocate(imgSource.getWidth(), imgSource.getHeight(),
		OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	int mx = mouseX;
	int my = mouseY;

	for (int y = 0; y < imgSource.getHeight(); y++) {
		for (int x = 0; x < imgSource.getWidth(); x++) {

			ofColor transferColor = imgSource.getColor(x, y);
			// Est ce que je suis dans le cercle ?
			float a = my - y;
			float b = mx - x;
			float longueur = sqrt(a * a + b * b);
			if (longueur > 200) {
				// Je suis hors du cercle, je dessine les carrés
				if (x % 20 == 0 && y % 20 == 0) {
					for (int j = 0; j < 20; j++) {
						for (int i = 0; i < 20; i++) {
							if (x + i < imgSource.getWidth() && y + j < imgSource.getHeight()) {
								imgResult.setColor(x + i, y + j, transferColor);
							}
						}
					}
				}
			} else {
				imgResult.setColor(x, y, transferColor);
				/*
				if (x % 20 == 0 && y % 20 == 0) {
					int taille = 20 * (longueur / 200.0f);
					for (int j = 0; j < taille; j++) {
						for (int i = 0; i < taille; i++) {
							if (x + i < imgResult.getWidth() && y + j < imgResult.getHeight()) {
								imgResult.setColor(x + i, y + j, transferColor);
							}
						}
					}
				}
				*/
			}

		}
	}
	imgResult.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	//imgSource.draw(0, 0);
	imgResult.draw(0, 0);
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
