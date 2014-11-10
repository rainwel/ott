//
//  SplashFrame.h
//  awesomeott
//
//  Created by yiliao6 on 9/11/14.
//
//

#ifndef __awesomeott__SplashFrame__
#define __awesomeott__SplashFrame__
#include "base/gBase.h"
#include "ui/base/Frame.h"

NS_OTT_BEGIN
class SplashFrame : public Frame {
public:
  CREATE_FUNC(SplashFrame);
  bool init();
  void onEnter();

private:
  void loadWidgets();
  void loadHomeFrame(float dt);
};

NS_OTT_END
#endif /* defined(__awesomeott__SplashFrame__) */
