//
//  Router.h
//  awesomeott
//
//  Created by Rui Wei on 10/17/14.
//
//

#ifndef __awesomeott__Router__
#define __awesomeott__Router__
#include "base/gBase.h"
#include "ApplicationInfo.h"
#include "ui/base/Frame.h"

NS_OTT_BEGIN
class Router {
public:
  static Router *getInstance();

  Router(){};
  ~Router(){};
  static Router *create();

  //  CREATE_FUNC(Router);

  virtual bool init();
  void push(const char *pURL, NextActionType method = SHOW_LOADING,
            int iZOrder = 0);
  void push(Frame *pFrame, NextActionType method = PUSH_FRAME, int iZOrder = 0);
  void pushDirectUrl(const char *url);
  void pop();
  void popFromDialog();

  void loadSplash();
  CC_SYNTHESIZE(Scene *, m_pScene, Scene);

private:
  static Router *m_pRouter;
};

NS_OTT_END

#endif /* defined(__awesomeott__Router__) */
