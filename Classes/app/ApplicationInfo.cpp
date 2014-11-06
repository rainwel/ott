//
//  ApplicationInfo.cpp
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#include "ApplicationInfo.h"
NS_OTT_BEGIN

ApplicationInfo *ApplicationInfo::m_pApplicationInfo = NULL;

ApplicationInfo *ApplicationInfo::getInstance() {
  if (m_pApplicationInfo == NULL) {
    m_pApplicationInfo = new ApplicationInfo();
    m_pApplicationInfo->init();
  }
  return m_pApplicationInfo;
}

bool ApplicationInfo::init() {
  setBool(BoolKey_MiDetailPage, (g_OTT_STYLE == OTT_STYLE_MIUI));
  setBool(BoolKey_ShowFlyFrame, (g_OTT_STYLE == OTT_STYLE_MIUI));
  setBool(BoolKey_MiVerticalList, (g_OTT_STYLE == OTT_STYLE_MIUI));
  setBool(BoolKey_StayonBackground, true);
  setBool(BoolKey_ShowQuit, true);
  setBool(BoolKey_ShowRemoteInstall, true);
  setBool(BoolKey_ShowHomeLogo, true);
  setBool(BoolKey_ShowRecommendApp, true);
  setBool(BoolKey_ShowUninstall, true);
  setBool(BoolKey_ShowAppPage, true);
  setBool(BoolKey_ShowSettingPage, true);
  setBool(BoolKey_ShowUpgradePrompt, true);
  setBool(BoolKey_WHTVideo, true);
  setBool(BoolKey_TargetForIOS, true);
  setBool(BoolKey_ShowMIShadow, true);
  setBool(BoolKey_ShowReflection, true);

  setInt(IntKey_TotalMemoryMB, 1);
  setInt(IntKey_CocosState, -1);

  return true;
}

#pragma mark - Get / Set String
string ApplicationInfo::getString(int nKey) {
  map<int, string>::iterator ite = m_mapString.find(nKey);
  if (ite != m_mapString.end()) {
    return ite->second;
  }
  return "";
}

void ApplicationInfo::setString(int nKey, const char *val) {
  m_mapString.erase(nKey);
  m_mapString.insert(pair<int, string>(nKey, val));
}

#pragma mark - Get / Set Boolean
bool ApplicationInfo::getBool(int nKey) {
  map<int, bool>::iterator ite = m_mapBoolean.find(nKey);
  if (ite != m_mapBoolean.end()) {
    return ite->second;
  }
  return false;
}

void ApplicationInfo::setBool(int nKey, bool val) {
  m_mapBoolean.erase(nKey);
  m_mapBoolean.insert(pair<int, bool>(nKey, val));
}

#pragma mark - Get / Set Integer
int ApplicationInfo::getInt(int nKey) {
  map<int, int>::iterator ite = m_mapInteger.find(nKey);
  if (ite != m_mapInteger.end()) {
    return ite->second;
  }
  return 0;
}

void ApplicationInfo::setInt(int nKey, int ival) {
  m_mapInteger.erase(nKey);
  m_mapInteger.insert(pair<int, int>(nKey, ival));
}

void ApplicationInfo::Dlog(const char *format, ...) {

}

NS_OTT_END