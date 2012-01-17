#pragma once

#include "ofMain.h"
#include "ofGraphics.h"
#include "ofxOpenCv.h"
#include "kinectManager.h"

#ifndef True
#define True true
#endif

#ifndef False
#define False false
#endif

class quad: public ofNode
{

public:
    quad()
    {
    }

    ofPoint corners[4];
    ofPoint center;

    ofPoint src[4];
    ofPoint dst[4];
    //lets make a matrix for openGL
    //this will be the matrix that peforms the transformation
    GLfloat matrix[16];
    ofTrueTypeFont ttf;
    // img and video stuff
    ofImage img;
    ofImage slide;
    ofVideoPlayer video;
    ofTexture videoTex;

    int videoWidth;
    int videoHeight;
    unsigned char * videoAlphaPixels;
    unsigned char * videoPixels;

    int borderColor;
    ofFloatColor bgColor;
    ofFloatColor secondColor;
    ofFloatColor startColor;
    ofFloatColor endColor;
    ofFloatColor transColor;
    ofFloatColor imgColorize;
    ofFloatColor videoColorize;
    ofFloatColor camColorize;
    ofFloatColor colorGreenscreen;
    ofFloatColor kinectColorize;

    int bgAlpha;

    // camera stuff
    ofTexture camTexture;
    ofTexture camAlphaTexture;
    int camWidth;
    int camHeight;
    unsigned char * camPixels;
    unsigned char * camAlphaPixels;
    ofVideoGrabber * camera;

    int layer;

    float camMultX;
    float camMultY;
    float imgMultX;
    float imgMultY;
    float kinectMultX;
    float kinectMultY;
    float videoMultX;
    float videoMultY;
    float videoSpeed;
    float previousSpeed;
    float slideshowSpeed;
    float transDuration;
    float edgeBlendExponent;
    float edgeBlendAmountSin;
    float edgeBlendAmountDx;
    float edgeBlendAmountTop;
    float edgeBlendAmountBottom;
    float edgeBlendGamma;
    float edgeBlendLuminance;

    int quadNumber;

    bool initialized;
    bool isActive;
    bool isSetup;
    bool isOn;
    bool isMaskSetup;
    bool colorBg;
    bool transBg;
    bool transUp;
    bool camBg;
    bool camGreenscreen;
    bool imgBg;
    bool videoBg;
    bool videoSound;
    bool videoLoop;
    bool videoGreenscreen;
    bool slideshowBg;
    bool slideFit;
    bool slideKeepAspect;
    bool kinectBg;
    bool kinectImg;
    bool kinectMask;
    int nearDepthTh;
    int farDepthTh;
    int kinectBlur;
    float kinectContourMin;
    float kinectContourMax;
    float kinectContourSimplify;
    int kinectContourSmooth;
    bool getKinectContours;
    bool getKinectGrayImage;
    bool kinectContourCurved;

    bool videoHFlip;
    bool imgHFlip;
    bool camHFlip;
    bool videoVFlip;
    bool imgVFlip;
    bool camVFlip;
    bool edgeBlendBool;

    bool bBlendModes;
    int blendMode;

    bool bMask;
    bool maskInvert;
    int maskMode;

    bool bHighlightCorner;
    int highlightedCorner;

    int videoVolume;
    int thresholdGreenscreen;
    int bgSlideshow;
    unsigned int currentSlide;
    int transStep;
    int transCounter;
    int fps;
    int slideFramesDuration;
    int slideTimer;

    vector<string> videos;
    vector<string> slideshows;
    vector<string> slidesnames;
    vector<ofImage> slides;

    string bgImg;
    string bgVideo;
    string loadedImg;
    string loadedVideo;
    string loadedSlideshow;

    ofShader * shaderBlend;
    ofFbo   quadFbo;
    ofFbo::Settings settings;

    ofShader * maskShader;
    ofFbo maskFbo;
    ofFbo::Settings maskFboSettings;

    kinectManager * quadKinect;
    ofxCvGrayscaleImage kinectThreshImage;
    ofxCvGrayscaleImage kinectContourImage;
    ofxCvContourFinder kinectContourFinder;
    ofPath kinectPath;

    ofFbo targetFbo;

    int quadDispX;
    int quadDispY;
    int quadW;
    int quadH;

    // a func for reading a dir content to a vector of strings
    int getdir (string dir, vector<string> &files);


    void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, vector<string> &slideshowFolders, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofVideoGrabber &camGrabber, kinectManager &kinect);

    void update();

    void draw();

    //void gaussian_elimination(float *input, int n);

    //void findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]);

    void loadImageFromFile(string imgName, string imgPath);

    void loadVideoFromFile(string videoName, string videoPath);

    void allocateFbo(int w, int h);

    void maskAddPoint(int x, int y);
    void drawMaskMarkers();

    vector<ofPoint> maskPoints;
    ofVec3f getWarpedPoint(int x, int y);
    bool bHighlightMaskPoint;
    int highlightedMaskPoint;

    bool bDeform;

    bool isBezierSetup;
    bool bHighlightCtrlPoint;
    int highlightedCtrlPointRow;
    int highlightedCtrlPointCol;
    float bezierPoints[4][4][3];
    bool bBezier;
    float bezierCtrlPoints[4][4][3];

    bool bGrid;
    vector<vector<vector<float> > > gridPoints;
    vector<vector<vector<float> > > gridCtrlPoints;
    int gridRows;
    int gridColumns;
    void gridSurfaceSetup();
    void gridSurfaceUpdate();
    void drawGridMarkers();

    void bezierSurfaceSetup();
    void bezierSurfaceUpdate();
    void drawBezierMarkers();


};

