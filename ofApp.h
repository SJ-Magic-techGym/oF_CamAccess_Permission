/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/
#define ERROR_MSG(); printf("Error in %s:%d\n", __FILE__, __LINE__);

/************************************************************
************************************************************/
 class ofApp : public ofBaseApp{
private:
	enum{
		WINDOW_WIDTH	= 640,
		WINDOW_HEIGHT	= 480,
		
		VIDEO_WIDTH		= 640,
		VIDEO_HEIGHT	= 480,
	};
	
	ofVideoGrabber cam;
	int Cam_id;
	bool b_CamSearchFailed;
	
	ofFbo fbo;
	
	void setup_Camera();
	void update_fbo();
	void  ClearFbo(ofFbo& _fbo);

public:
	ofApp(int _Cam_id);
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
