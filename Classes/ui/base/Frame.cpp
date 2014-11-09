//
//  Frame.cpp
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#include "Frame.h"
#include "BottomMenu.h"
#include "app/ApplicationInfo.h"
#include "ui/shared/SplashFrame.h"

NS_OTT_BEGIN
Frame::Frame() {
  m_strFrameId = "";
  m_cFrameSize = Size::ZERO;
  m_bDisableBeback = false;
  m_pFocusedFragment = NULL;
  m_eRunningMode = FRAME;
  m_bHideTimer = false;
}

Frame::~Frame() {}

bool Frame::init() {
  if (Fragment::init()) {
    //    this->setTag(TAG_FRAME_ALPHA);
    appSetString(StrKey_CurrentPageId, "");
    m_lblTitle = Label::createWithSystemFont("", FONTNAME_BOLD, 34.0);
    addChild(m_lblTitle, 101);

    m_lblSubTitle = Label::createWithSystemFont("", FONTNAME_NORMAL, 21.0f);
    addChild(m_lblSubTitle, 101);

    m_cFrameSize = this->getContentSize();
    return true;
  }
  return false;
}

void Frame::setTitle(const char *pTitle) {
  m_lblTitle->setString(pTitle);
  Size size = m_lblTitle->getContentSize();
  m_lblTitle->setPosition(
      Point(kEGLViewWidth - size.width / 2 - 80, kEGLViewHeight - 70));
}

void Frame::setSubtitle(const char *pTitle) {
  m_lblSubTitle->setString(pTitle);

  Size size = m_lblSubTitle->getContentSize();

  m_lblSubTitle->setPosition(
      Point(kEGLViewWidth - 80 - size.width / 2, kEGLViewHeight - 100));
}

void Frame::addFragment(Fragment *pFragment) {

  pFragment->setFrameContainer(this);
  if (pFragment->getParent() == NULL) {
    addChild(pFragment);
  }

  m_pFragments.push_back(pFragment);
}

void Frame::insertFragment(Fragment *pFragment, int index) {
  pFragment->setFrameContainer(this);
  if (pFragment->getParent() == NULL) {
    addChild(pFragment);
  }
  m_pFragments.insert(m_pFragments.begin() + index, pFragment);
}

void Frame::removeFragment(Fragment *pFragment, bool bCleanup) {
  if (pFragment != NULL && pFragment->getFrameContainer() == this) {
    //    std::remove(m_pFragments.begin(), m_pFragments.end(), pFragment);
    for (int k = 0; k < m_pFragments.size(); k++) {
      if (m_pFragments.at(k) == pFragment) {
        m_pFragments.erase(m_pFragments.begin() + k);
        break;
      }
    }
    if (bCleanup) {
      pFragment->removeFromParentAndCleanup(true);
    }
  }
}

void Frame::onFocusBegan(int nDirection) {
  int icount = (int)m_pFragments.size();
  if (m_pFocusedFragment == NULL && icount > 0) {
    for (int i = 0; i < icount; i++) {
      Fragment *pFocusedFragment = m_pFragments.at(i);
      if (pFocusedFragment->isFocusable()) {
        m_pFocusedFragment = pFocusedFragment;
        break;
      }
    }
  }
  if (m_pFocusedFragment != NULL) {
    m_pFocusedFragment->onFocusBegan(nDirection);
  }
}

void Frame::onFocusEnded() {
  if (m_pFocusedFragment != NULL) {
    m_pFocusedFragment->onFocusEnded();
  }
}

void Frame::changeFocusedFragment(Fragment *frag) {
  if (frag != m_pFocusedFragment) {
    if (m_pFocusedFragment != NULL) {
      m_pFocusedFragment->onFocusEnded();
    }
    m_pFocusedFragment = frag;
  }
}

int Frame::onKeyEvent(int nKey) {

  switch (nKey) {
  case KEY_BACK:
    //    Router::getInstance()->pop();
    break;
  case KEY_OK:
  case KEY_UP:
  case KEY_DOWN:
  case KEY_LEFT:
  case KEY_RIGHT:
    fireKeyEvent(nKey);
    break;
  default:
    break;
  }

  return 0;
}

//!!!: 焦点在不同的Fragment之间切换
void Frame::fireKeyEvent(int nKey) {
  if (m_pFocusedFragment == NULL) {
    return;
  }
  int nRet = m_pFocusedFragment->onKeyEvent(nKey);
  if (nRet > 0) {
    // Rain: onKeyEvent 返回值大于0时候，怎么办？
    DLog("nRet - %d", nRet);
    //    this->fireKeyEvent(nRet);
  } else if (nRet == 0) {
    if (nKey == KEY_LEFT || nKey == KEY_RIGHT || nKey == KEY_UP ||
        nKey == KEY_DOWN) {
      //      SoundUtil::getInstance()->playMoveEffect();
    }

  } else if (nRet == -9) {
    //// if it's -9, do not jump into sibling fragments.
    //    SoundUtil::getInstance()->playEdgeEffect();
  } else {

    switch (nKey) {
    case KEY_UP:
    case KEY_LEFT:
    case KEY_RIGHT: {
      if (!changeFragment(nKey)) {
        //        SoundUtil::getInstance()->playEdgeEffect();
      }

    } break;

    case KEY_DOWN: {
      if (changeFragment(nKey)) {
        return;
      }

      //!!!: 在万花筒首页，进入消息中心
      if (m_strFrameId.find("home") == 0
          //         &&  Router::getInstance()->onFocusedTimeWifiPad()
          ) {
        if (m_pFocusedFragment != NULL) {
          m_pFocusedFragment->onFocusEnded();
        }
        m_pFocusedFragment = NULL;
      }

      // 没有可以选中的fragment了, 到达边界
      //      SoundUtil::getInstance()->playEdgeEffect();
    } break;

    default: {
      //      SoundUtil::getInstance()->playEdgeEffect();
    } break;
    }
  }
}

bool Frame::changeFragment(int nKey) {
  Point fousedPos = m_pFocusedFragment->getPosition();
  bool bFound = false;
  Fragment *foundFrag = NULL;
  Point foundPos = Point::ZERO;
  Fragment *pFragment = NULL;
  for (int k = 0; k < m_pFragments.size(); k++) {

    pFragment = m_pFragments.at(k);
    if (pFragment == m_pFocusedFragment) {
      continue;
    }

    Point curPos = pFragment->getPosition();

    switch (nKey) {
    case KEY_LEFT: {
      bFound = curPos.x < fousedPos.x && curPos.y < fousedPos.y + 10 &&
               curPos.y > fousedPos.y - 10;
      if (curPos.x == fousedPos.x) {
        bFound = true;
      }
    } break;
    case KEY_RIGHT: {
      if (fousedPos.x < 0) {
        return false;
      }
      bFound = curPos.x > fousedPos.x && curPos.y < fousedPos.y + 10 &&
               curPos.y > fousedPos.y - 10;
      if (curPos.x == fousedPos.x) {
        bFound = true;
      }
    } break;
    case KEY_UP: {
      bFound = curPos.y > fousedPos.y;
      if (bFound && foundFrag != NULL &&
          abs((int)(foundPos.y - fousedPos.y)) <
              abs((int)(curPos.y - fousedPos.y))) {
        bFound = false;
      }
    } break;
    case KEY_DOWN: {
      bFound = curPos.y < fousedPos.y;
      if (bFound && foundFrag != NULL &&
          abs((int)(foundPos.y - fousedPos.y)) <
              abs((int)(curPos.y - fousedPos.y))) {
        bFound = false;
      }
    } break;
    default:
      break;
    }

    if (bFound && pFragment->isFocusable()) {
      foundFrag = pFragment;
      foundPos = curPos;
    }
  }
  if (foundFrag != NULL) {
    m_pFocusedFragment->onFocusEnded();
    foundFrag->onFocusBegan(nKey);
    m_pFocusedFragment = foundFrag;
    this->onFragmentChanged();
    return true;
  } else if (foundFrag == NULL && g_OTT_STYLE == OTT_STYLE_MIUI &&
             nKey == KEY_UP && this->getTag() == TAG_FRAME_HOME) {
    //    Router::getInstance()->swapNotifyBar(true);
  }

  return false;
}

BaseBox *Frame::getFocusedBox() {
  if (m_pFocusedFragment != NULL) {
    return m_pFocusedFragment->getFocusedBox();
  }
  return NULL;
}

void Frame::refreshBottomMenu() {
  Fragment *pFragment;

  for (int k = 0; k < m_pFragments.size(); k++) {

    pFragment = m_pFragments.at(k);

    if (pFragment->getTag() == TAG_WIDGET_BOTTOMMENU) {
      DLog("refreshBottomMenu - ");
      BottomMenu *bMenu = dynamic_cast<BottomMenu *>(pFragment);
      if (bMenu != NULL) {
        //        bMenu->refreshNotice(true);
      }
      break;
    }
  }
}

#pragma mark - Fragment change focus
void Frame::changeFocusedByPostion(Point pos) {
  Size size = Size(60, 50);
  if (pos.x > kEGLViewWidth - size.width &&
      pos.y > kEGLViewHeight - size.height) {
    //    Router::getInstance()->pop();
  }
}

Frame *Frame::createFrameByString(const char *frameName) {

  Frame *retFrame = NULL;
  if (strcasecmp(frameName, "SplashFrame") == 0) {
    retFrame = SplashFrame::create();
  }
  return retFrame;
}

NS_OTT_END