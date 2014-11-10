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

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(
        "shared/splash/splash_sheet.plist");

    loadWidgets();
    ret = true;
  } while (0);
  return ret;
}

void SplashFrame::loadWidgets() {
  auto pBack = Sprite::create("shared/Default.jpg");
  pBack->setPosition(Point(kEGLViewWidth / 2, kEGLViewHeight / 2));
  pBack->setTag(TAG_WIDGET_BACKGROUND);
  this->addChild(pBack, 0);

  auto pLogo = Sprite::createWithSpriteFrameName("booting-logo.png");
  pLogo->setPosition(Point(kEGLViewWidth / 2, kEGLViewHeight / 2 + 80));
  pLogo->setAnchorPoint(Point(0.5, 0.5));
  pLogo->setTag(TAG_WIDGET_LOGO);
  this->addChild(pLogo);

  auto pTitle = Sprite::createWithSpriteFrameName("booting_title_new.png");
  pTitle->setPosition(Point(kEGLViewWidth / 2, kEGLViewHeight / 2 - 40));
  pTitle->setAnchorPoint(Point(0.5, 0.5));
  pTitle->setTag(TAG_WIDGET_TITLE);
  this->addChild(pTitle);

  /*CCSprite *pLogoSprite = CCSprite::create("splash/booting-logo.png");
  pLogoSprite->setAnchorPoint(ccp(0.5, 0.5));
  pLogoSprite->setPosition(ccp(winSize.width / 2, 420));
  pLogoSprite->setTag(TAG_FRAME_LOGO);
  this->addChild(pLogoSprite, 2);

  CCSprite *pLogoTitle = CCSprite::create("splash/booting_title_new.png");
  pLogoTitle->setAnchorPoint(ccp(0.5f, 1.0f));
  pLogoTitle->setPosition(ccp(winSize.width / 2, 310));
  this->addChild(pLogoTitle);*/
}

NS_OTT_END