//
//  Fragment.h
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#ifndef __awesomeott__Fragment__
#define __awesomeott__Fragment__

#include "base/gBase.h"

NS_OTT_BEGIN

class Frame;
class BaseBox;

class Fragment : public Layer {
public:
  Fragment() {
    m_pFrameContainer = NULL;
    m_bFocusable = true;

    m_bFocused = false;
  }

  ~Fragment(){};

  virtual bool isFocusable() { return m_bFocusable; };

  virtual void onFocusBegan(int nDirection) = 0;
  virtual void onFocusEnded() = 0;
  virtual int onKeyEvent(int nKey) { return 0; };

  virtual BaseBox *getFocusedBox() { return NULL; };

  virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
  virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
  virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

  void changeTouchable(bool bVal);
  virtual void changeFocusedByPostion(Point pos) {
    DLog("pos.x-y - %d-%d", (int)pos.x, (int)pos.y);
  };

  CC_SYNTHESIZE(Frame *, m_pFrameContainer, FrameContainer);
  CC_SYNTHESIZE(bool, m_bFocusable, Focusable);
  CC_SYNTHESIZE(bool, m_bFocused, Focused);

private:
  Point m_touchBeginPoint;
  Point m_touchLastPoint;

  struct timeval m_touchBeginTime;
  struct timeval m_touchEndTime;

  bool isTouchInside(Touch *pTouch);
};

NS_OTT_END

#endif /* defined(__awesomeott__Fragment__) */
