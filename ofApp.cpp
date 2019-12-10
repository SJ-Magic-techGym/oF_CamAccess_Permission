/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(int _Cam_id)
: Cam_id(_Cam_id)
, b_CamSearchFailed(false)
{
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("Cam test");
	
	ofSetWindowShape( WINDOW_WIDTH, WINDOW_HEIGHT );
	/*
	ofSetVerticalSync(false);
	ofSetFrameRate(0);
	/*/
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	//*/
	
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	setup_Camera();
	if(b_CamSearchFailed){
		printf("Cam Search Failed\n");
		fflush(stdout);
		
		std::exit(1);
	}
	
	fbo.allocate(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA);
	ClearFbo(fbo);
}

/******************************
******************************/
void ofApp::setup_Camera()
{
	/********************
	********************/
	printf("> setup camera\n");
	fflush(stdout);
	
	ofSetLogLevel(OF_LOG_VERBOSE);
    cam.setVerbose(true);
	
	vector< ofVideoDevice > Devices = cam.listDevices();// 上 2行がないと、List表示されない.
	
	/********************
	search for camera by device name.
	********************/
	if(Cam_id == -2){
		Cam_id = -1;
		
		int i;
		for(i = 0; i < Devices.size(); i++){
			/********************
			Device Nameが、変わってしまう可能性があるため、
			「内蔵Camでないもので、最初に見つかったカメラ」と言う条件に変更した。
			********************/
			if(Devices[i].deviceName == "HD Pro Webcam C920" ){
			// if(Devices[i].deviceName != "FaceTime HD Camera" ){ // for my mac.
				Cam_id = i;
				break;
			}
		}
		
		if(i == Devices.size()){
			b_CamSearchFailed = true;
			return;
		}
	}
	
	/********************
	********************/
	if(Cam_id == -1){
		std::exit(1);
	}else{
		if(Devices.size() <= Cam_id) { ERROR_MSG(); std::exit(1); }
		
		cam.setDeviceID(Cam_id);
		cam.initGrabber(VIDEO_WIDTH, VIDEO_HEIGHT);
		
		printf("> CamName = %s\n", Devices[Cam_id].deviceName.c_str());
		printf("> Cam size asked = (%d, %d), actual = (%d, %d)\n", int(VIDEO_WIDTH), int(VIDEO_HEIGHT), int(cam.getWidth()), int(cam.getHeight()));
		fflush(stdout);
	}
	
	return;
}

/******************************
******************************/
void ofApp::ClearFbo(ofFbo& _fbo){
	_fbo.begin();
		ofClear(0, 0, 0, 0);
	_fbo.end();
}

/******************************
******************************/
void ofApp::update(){
	/********************
	********************/
    cam.update();
    if(cam.isFrameNew())	{ update_fbo(); }
}

/******************************
******************************/
void ofApp::update_fbo(){
	fbo.begin();
		ofClear(0);
		ofSetColor(255);
		cam.draw(0, 0, fbo.getWidth(), fbo.getHeight());
	fbo.end();
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
