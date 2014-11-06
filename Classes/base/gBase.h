//
//  gBase.h
//  awesomeott
//
//  Created by Rui Wei on 10/17/14.
//
//

#ifndef __awesomeott__gBase__
#define __awesomeott__gBase__

#include <stdio.h>
#include <pthread.h>
#include <string>
#include <iostream>

#include "gEnum.h"
#include "gMacro.h"

#include "cocos2d.h"

#include "utils/strUtil.h"

#include "protobuf/ProtobufWarpper.h"

using namespace cocos2d;
using namespace ottenum;
using namespace std;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#endif

extern OTT_STYLE g_OTT_STYLE;

// 全局的时间戳，App中需要取当前时间的请使用此全局变量
extern long g_UNIX_TIME_STAMP;

// 网络状态
extern int g_NetworkStatus;
extern std::string g_NetworkName;

extern int kCCDebugMode;
extern int kEGLViewWidth;
extern int kEGLViewHeight;
extern float kEGLViewRatio;

extern pthread_t g_MainThreadID;

#define DLog(fmt, ...)                                                       \
  strUtil::getInstance()->logInfo(kCCDebugMode, ("%s [Line %d] " fmt), __PRETTY_FUNCTION__, \
                   __LINE__, ##__VA_ARGS__)

#endif /* defined(__awesomeott__gBase__) */
