//
//  SplashFrame.cpp
//  awesomeott
//
//  Created by yiliao6 on 9/11/14.
//
//

#include "SplashFrame.h"

NS_OTT_BEGIN
bool SplashFrame::init() {
  bool ret = false;
  do {
    CC_BREAK_IF(!Frame::init());
    this->setTag(TAG_FRAME_SPLASH);
    loadWidgets();
    ret = true;
  } while (0);
  return ret;
}

void SplashFrame::loadWidgets() {
  Sprite *pBack = Sprite::create("img720/shared/Default.jpg");
  pBack->setPosition(Point(kEGLViewWidth / 2, kEGLViewHeight / 2));
  pBack->setTag(TAG_WIDGET_BACKGROUND);
  this->addChild(pBack, 0);
    
 
}

NS_OTT_END