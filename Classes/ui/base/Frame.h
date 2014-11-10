//
//  Frame.h
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#ifndef __awesomeott__Frame__
#define __awesomeott__Frame__

#include "base/gBase.h"
#include "Fragment.h"
NS_OTT_BEGIN
class Frame : public Fragment {
public:
  enum RunningMode { FRAME, DIALOG };

  Frame();
  ~Frame();

  CREATE_FUNC(Frame);

  bool init();

  void setTitle(const char *pTitle);
  void setSubtitle(const char *pSubtitle);

  virtual void addFragment(Fragment *pFragment);
  virtual void insertFragment(Fragment *pFragment, int index = 0);
  virtual void removeFragment(Fragment *pFragment, bool bCleanup = false);
  void changeFocusedFragment(Fragment *frag);

  virtual int onKeyEvent(int nKey);

  virtual void onFocusBegan(int iDir);
  virtual void onFocusEnded();
  virtual BaseBox *getFocusedBox();
  virtual void onFragmentChanged(){};

  virtual void refreshHome(){};
  virtual void refreshBottomMenu();

  virtual bool isKeyEventCustomized() { return false; };

  virtual void loadWidgets(){};

  static Frame *createFrameByTag(int itag);

  CC_SYNTHESIZE(Fragment *, m_pFocusedFragment, FocusedFragment);
  CC_SYNTHESIZE(RunningMode, m_eRunningMode, RunningMode);
  CC_SYNTHESIZE(bool, m_bHideTimer, HideTimer);
  CC_SYNTHESIZE(bool, m_bDisableBeback, DisableBeback);
  CC_SYNTHESIZE_STRING(m_strFrameId, FrameId);

protected:
  Size m_cFrameSize;

private:
  Label *m_lblTitle;
  Label *m_lblSubTitle;
  vector<Fragment *> m_pFragments;
  bool changeFragment(int nKey);
  void fireKeyEvent(int nKey);

  virtual void changeFocusedByPostion(Point pos);
};
NS_OTT_END

#endif /* defined(__awesomeott__Frame__) */
