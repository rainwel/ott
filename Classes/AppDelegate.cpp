#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "app/Router.h"

USING_NS_CC;
USING_NS_OTT;

OTT_STYLE g_OTT_STYLE = OTT_STYLE_WHTUI;
int kCCDebugMode = 1;

float kEGLViewRatio = 1.0f;
float kEGLViewWidth = 1280.0;
float kEGLViewHeight = 720.0;

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
    director->setOpenGLView(glview);
  }

  // turn on display FPS
  director->setDisplayStats(true);

  // set FPS. the default value is 1.0/60 if you don't call this
  director->setAnimationInterval(1.0 / 60);

  glview->setDesignResolutionSize(kEGLViewWidth, kEGLViewHeight,
                                  ResolutionPolicy::SHOW_ALL);
  director->setContentScaleFactor(kEGLViewRatio);

  // create a scene. it's an autorelease object
  //  auto scene = HelloWorld::createScene();
  director->runWithScene(Router::getInstance()->getScene());
  DLog("Done, %s, %d", "aaa", 123);

  int srcFolder = 720.0f * kEGLViewRatio;
  string strFolder = StringUtils::format("img%d", srcFolder);
  FileUtils::getInstance()->addSearchPath(strFolder);

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
