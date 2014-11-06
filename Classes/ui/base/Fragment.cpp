//
//  Fragment.cpp
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#include "Fragment.h"
#include "app/ApplicationInfo.h"
NS_OTT_BEGIN

bool Fragment::isTouchInside(Touch *pTouch) {
  Point local2 = this->convertTouchToNodeSpace(pTouch);
  Point local = this->convertToNodeSpace(pTouch->getLocation());
  Point localView = pTouch->getLocationInView();
  Rect rect = Rect::ZERO;
  rect.size = this->getContentSize();
  return this->getContentSize().height > local2.y && local2.y > 0;
  //  return rect.containsPoint(local2);
}

bool Fragment::onTouchBegan(Touch *pTouch, Event *pEvent) {
  if (!appBool(BoolKey_TouchEnabled)) {
    return false;
  }
  bool isTouched = isTouchInside(pTouch);
  if (isTouched) {
    m_touchBeginPoint = pTouch->getLocation();
    m_touchLastPoint = pTouch->getLocation();
    gettimeofday(&m_touchBeginTime, NULL);
  }
  return isTouched;
}

void Fragment::onTouchMoved(Touch *pTouch, Event *pEvent) {
  if (!appBool(BoolKey_TouchEnabled)) {
    return;
  }
  m_touchLastPoint = pTouch->getLocation();
  Layer::onTouchMoved(pTouch, pEvent);
}

void Fragment::onTouchEnded(Touch *pTouch, Event *pEvent) {
  if (!appBool(BoolKey_TouchEnabled) || !this->isVisible()) {
    return;
  }
  gettimeofday(&m_touchEndTime, NULL);
  bool isTouchMove = true;
  float moveRange = 10;
  long timediff = m_touchEndTime.tv_sec - m_touchBeginTime.tv_sec;
  timediff = timediff * 1000 +
             (m_touchEndTime.tv_usec - m_touchBeginTime.tv_usec) / 1000;
  float dx = m_touchBeginPoint.x - m_touchLastPoint.x;
  float dy = m_touchBeginPoint.y - m_touchLastPoint.y;
  // 触屏时间少于150ms
  if (timediff < 150) {
    if ((-moveRange < dx && dx < moveRange) &&
        (-moveRange < dy && dy < moveRange)) {
      isTouchMove = false;
    }
  }
  if (!isTouchMove) {
    Point local2 = this->convertTouchToNodeSpace(pTouch);
    //    CCPoint local = this->convertToNodeSpace(m_touchLastPoint);
    //    CCPoint local2 = this->convertToWorldSpace(m_touchLastPoint);
    changeFocusedByPostion(local2);
  }

  Layer::onTouchEnded(pTouch, pEvent);
}

NS_OTT_END