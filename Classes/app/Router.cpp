//
//  Router.cpp
//  awesomeott
//
//  Created by Rui Wei on 10/17/14.
//
//

#include "Router.h"

NS_OTT_BEGIN

Router *Router::m_pRouter = NULL;

Router *Router::getInstance() {
  if (m_pRouter == NULL) {
    m_pRouter = Router::create();
  }
  return m_pRouter;
}

Router *Router::create() {
  Router *obj = new Router();
  if (obj && obj->init()) {
    return obj;
  }
  delete obj;
  return NULL;
}

bool Router::init() {
  m_pScene = Scene::create();

  return true;
}

void Router::push(const char *pURL, NextActionType method, int iZOrder) {}

void Router::push(Frame *pFrame, NextActionType method, int iZOrder) {}

void Router::pushDirectUrl(const char *url) {}

void Router::pop() {}

void Router::popFromDialog() {}

void Router::loadSplash() {
  Frame *pFrame = Frame::createFrameByTag(TAG_FRAME_SPLASH);
  m_pScene->addChild(pFrame);
}

NS_OTT_END