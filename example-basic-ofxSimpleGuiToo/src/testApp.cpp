#include "testApp.h"

// for demonstrating adding any drawable object (that extends ofBaseDraw);
ofVideoGrabber		vidGrabber;
unsigned char * 	videoInverted;
ofTexture			videoTexture;


ofPoint *points;
ofPoint	v[300];



void addToggle(ofxSyncedParameter<bool>& param)
{
    gui.addToggle(param.getName(), param.value);
    param.startUpdating();

}
ofxSimpleGuiSliderInt& addSlider(ofxSyncedParameter<int>& param)
{
    param.startUpdating();
    return gui.addSlider(param.getName(), param.value, param.getMin(), param.getMax());
}

ofxSimpleGuiSliderFloat& addSlider(ofxSyncedParameter<float>& param)
{
    param.startUpdating();
    return gui.addSlider(param.getName(), param.value, param.getMin(), param.getMax());
}

void addButton(ofxSyncedParameter<bool>& param)
{
    gui.addButton(param.getName(), param.value);
    param.startUpdating();
}

void addColorPicker(ofxSyncedParameter<ofFloatColor>& param)
{
    gui.addColorPicker(param.getName(), param.value);
    param.startUpdating();
}

//--------------------------------------------------------------
void testApp::setup(){	 
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	// for demonstrating adding any drawable object (that extends ofBaseDraw);
	vidGrabber.initGrabber(320, 240);	
	videoInverted 	= new unsigned char[int(vidGrabber.getWidth() * vidGrabber.getHeight() * 3)];
	videoTexture.allocate(vidGrabber.getWidth(), vidGrabber.getHeight(), GL_RGB);
	
	
	// 'gui' is a global variable declared in ofxSimpleGuiToo.h
	gui.addTitle("A group");
    myBool1Animate.set("myBool1 Animate", false);
    addToggle(myBool1Animate);
    myFloat1.set("myFloat1: noise", myFloat1, 0.0, 1);
    addSlider(myFloat1);
    
	myInt1.set("myInt1", 0, 100, 200);
	//gui.addComboBox("box1", box1, 12, NULL);
    randomizeButton.set("Randomize Background", false);
    addButton(randomizeButton);
    aColor.set("BG Color", ofColor::white);
    addColorPicker(aColor);
	
	// start a new group
	gui.addTitle("Another group");
    myFloat2.set("myFloat2", 0, 0.0f, 1.0f);
    addSlider(myFloat2).setSmoothing(0.5);
    
	myInt2.set("myInt2", 0, 3, 8);
    addSlider(myInt2);
    
	myBool2.set("myBool2", myBool2);
    addToggle(myBool2);
    
	//string titleArray[] = {"Lame", "Alright", "Better", "Best"};
	//gui.addComboBox("box2", box2, 4,  titleArray);
	gui.addFPSCounter();
	
	// new group, this time separate into it's own column
	gui.addTitle("Yes one more group").setNewColumn(true);
    
    myBool4.set("myBool4", false);
    addToggle(myBool4);
    
    myBool3.set("myBool3", false);
    addToggle(myBool3);
    

    myFloat3.set("myFloat3", 0, 0.0, 1);
    addSlider(myFloat3).setSmoothing(0.8);
    
    myFloat4.set("myFloat4", 0, 0.0, 20);
    addSlider(myFloat4).setSmoothing(1);
	myInt6.set("myInt6", 0, 0, 10);
    addSlider(myInt6);
    
	myInt4.set("myInt4", 0, 320, 1280);
    addSlider(myInt4);

	gui.addContent("Camera feed", vidGrabber);
	gui.addContent("Inverted", videoTexture);
	
	
	gui.addPage("A new page");		// use '[' ']' to cycle through pages, or keys 1-9
	myInt5.set("myInt5", myInt5, 2, 5);
	myInt7.set("myInt7",  0, 0, 100);
	myInt8.set("myInt8",  0, 10, 50);
	myInt3.set("myInt3",  0, 0, 100);
    myFloat7.set("myFloat7",  0, 0.0, 1);
    addSlider(myFloat7).setSmoothing(0.0);		// default
    myFloat8.set("myFloat8",  0, 0.0, 0.1);
    addSlider(myFloat8).setSmoothing(0.5);
    myInt9.set("myInt9",  0, 0, 10);
    addSlider(myInt9).setSmoothing(0.9);
	
	gui.addTitle("Final group?");
	myBool5.set("myBool5", false);
    addToggle(myBool5);
    
	myBool6.set("myBool6", false);
    addToggle(myBool6);
	myBool7.set("myBool7", false);
    addToggle(myBool7);

	myBool8.set("myBool8", false);
    addToggle(myBool8);

	
	
	// by default each page is saved in an xml with the same name as display name
	// you can override this with ofxSimpleGuiPage::setXMLName(string s);
	// ofxSimpleGuiToo::addPage() returns reference to the page, so you can do it directly on one line
	// of save it in a variable for use later
	gui.addPage("My 3rd page").setXMLName("foo.xml");	
	myFloat5.set("myFloat5", 0, 0.0, 5);
    addSlider(myFloat5);
	myFloat6.set("myFloat6", 0, 0.0, 1);
    addSlider(myFloat6);

	myFloat9.set("myFloat9", 0, 0.0, 0.01 );
    addSlider(myFloat9);

	myBool9.set("myBool9", false);
    addToggle(myBool9);
	
	
	gui.loadFromXML();
	
	printf("myint : %i\n", myInt1.value);
	
	gui.show();
}

//--------------------------------------------------------------
void testApp::update(){
	if(myBool1Animate.value) myFloat1.value = ofNoise(ofGetElapsedTimef());
	
	if(randomizeButton.value) {
		randomizeButton.value = false;
		aColor.value.r = ofRandomuf();
		aColor.value.g = ofRandomuf();
		aColor.value.b = ofRandomuf();
	}
	
	
	// from ofVideoGrabber example (
	vidGrabber.update();
	if(vidGrabber.isFrameNew()){
		int totalPixels = vidGrabber.getWidth() * vidGrabber.getHeight() * 3;
		unsigned char * pixels = vidGrabber.getPixels();
		for(int i = 0; i < totalPixels; i++) videoInverted[i] = 255 - pixels[i];
		videoTexture.loadData(videoInverted, vidGrabber.getWidth(), vidGrabber.getHeight(), GL_RGB);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofBackground(aColor.r * 255, aColor.g * 255.0f, aColor.b * 255.0);
	
	gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed (int key){ 
	if(key>='0' && key<='9') {
		gui.setPage(key - '0');
		gui.show();
	} else {
		switch(key) {
			case ' ': gui.toggleDraw(); break;
			case '[': gui.prevPage(); break;
			case ']': gui.nextPage(); break;
			case 'p': gui.nextPageWithBlank(); break;
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
}
