#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "app/Router.h"

USING_NS_CC;
USING_NS_OTT;

OTT_STYLE g_OTT_STYLE = OTT_STYLE_WHTUI;
int kCCDebugMode = 1;

float kEGLViewRatio = 1.0f;
int kEGLViewWidth = 1280;
int kEGLViewHeight = 720;

int g_NetworkStatus = -1;
string g_NetworkName = "";

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() {
  // initialize director
  auto director = Director::getInstance();
  auto glview = director->getOpenGLView();
  if (!glview) {
    glview = GLView::create("Awesome OTT");
    glview->setDesignResolutionSize(kEGLViewWidth, kEGLViewHeight,
                                    ResolutionPolicy::SHOW_ALL);

    director->setOpenGLView(glview);
    director->setContentScaleFactor(kEGLViewRatio);
  }

  // turn on display FPS
  director->setDisplayStats(true);

  // set FPS. the default value is 1.0/60 if you don't call this
  director->setAnimationInterval(1.0 / 60);

  // create a scene. it's an autorelease object
  //  auto scene = HelloWorld::createScene();
  director->runWithScene(Router::getInstance()->getScene());
  DLog("Done, %s, %d", "aaa", 123);

  Router::getInstance()->loadSplash();
  // run
  //  director->runWithScene(scene);

  return true;
}

// This function will be called when the app is inactive. When comes a phone
// call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
  Director::getInstance()->stopAnimation();

  // if you use SimpleAudioEngine, it must be pause
  // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
  Director::getInstance()->startAnimation();

  // if you use SimpleAudioEngine, it must resume here
  // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
