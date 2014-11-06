//
//  ApplicationInfo.h
//  awesomeott
//
//  Created by yiliao6 on 26/10/14.
//
//

#ifndef __awesomeott__ApplicationInfo__
#define __awesomeott__ApplicationInfo__

#include "base/gBase.h"

NS_OTT_BEGIN
#define appBool(__Key__) ApplicationInfo::getInstance()->getBool(__Key__)
#define appSetBool(__Key__, __Value__)                                         \
  ApplicationInfo::getInstance()->setBool(__Key__, __Value__)

#define appInt(__Key__) ApplicationInfo::getInstance()->getInt(__Key__)
#define appSetInt(__Key__, __Value__)                                          \
  ApplicationInfo::getInstance()->setInt(__Key__, __Value__)

#define appURL(__Key__) ApplicationInfo::getInstance()->getString(__Key__)
#define appString(__Key__) ApplicationInfo::getInstance()->getString(__Key__)
#define appSetString(__Key__, __Value__)                                       \
  ApplicationInfo::getInstance()->setString(__Key__, __Value__)
#define appStringData(__Key__)                                                 \
  ApplicationInfo::getInstance()->getString(__Key__).data()

class ApplicationInfo {
public:
  ApplicationInfo(){};
  ~ApplicationInfo(){};

  static ApplicationInfo *getInstance();
  bool init();

  bool getBool(int nKey);
  void setBool(int nKey, bool val);

  string getString(int nKey);
  void setString(int nKey, const char *val);

  int getInt(int nKey);
  void setInt(int nKey, int ival);
	
	void Dlog(const char * format, ...);

private:
  static ApplicationInfo *m_pApplicationInfo;

  map<int, string> m_mapString;
  map<int, bool> m_mapBoolean;
  map<int, int> m_mapInteger;
};
NS_OTT_END
#endif /* defined(__awesomeott__ApplicationInfo__) */
