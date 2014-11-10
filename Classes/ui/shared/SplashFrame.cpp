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

  pLogo->setTag(TAG_WIDGET_LOGO);
  this->addChild(pLogo);

  auto pTitle = Sprite::createWithSpriteFrameName("booting_title_new.png");
  pTitle->setPosition(Point(kEGLViewWidth / 2, kEGLViewHeight / 2 - 45));

  pTitle->setTag(TAG_WIDGET_TITLE);
  //  this->addChild(pTitle);

  auto pChannel = Sprite::createWithSpriteFrameName("channel_360.png");
  Size channelSize = pChannel->getContentSize();
  pChannel->setPosition(Point(kEGLViewWidth - 40 - channelSize.width / 2,
                              channelSize.height / 2 + 30));
  this->addChild(pChannel);
}

void SplashFrame::onEnter() {
  Frame::onEnter();
  auto pLogo = (Sprite *)this->getChildByTag(TAG_WIDGET_LOGO);
  auto pSeq = RepeatForever::create(
      Sequence::create(EaseSineInOut::create(RotateBy::create(1.0, 120.0)),
                       DelayTime::create(0.2),
                       EaseSineInOut::create(RotateBy::create(1.0, 120.0)),
                       DelayTime::create(0.2),
                       EaseSineInOut::create(RotateBy::create(1.0, 120.0)),
                       DelayTime::create(0.2), NULL));
  pLogo->runAction(pSeq);

  this->scheduleOnce(schedule_selector(SplashFrame::loadHomeFrame), 2.0);
}

void SplashFrame::loadHomeFrame(float dt) {}
NS_OTT_END