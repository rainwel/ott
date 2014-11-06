//
//  gMacro.h
//  awesomeott
//
//  Created by Rui Wei on 10/17/14.
//
//

#ifndef __awesomeott__gMacro__
#define __awesomeott__gMacro__

#ifdef __cplusplus
#define NS_OTT_BEGIN namespace ott {
#define NS_OTT_END }
#define USING_NS_OTT using namespace ott
#else
#define NS_OTT_BEGIN
#define NS_OTT_END
#define USING_NS_OTT
#endif

#define CC_SYNTHESIZE_STRING(varName, funName)                                 \
private:                                                                       \
  std::string varName;                                                         \
                                                                               \
public:                                                                        \
  virtual std::string get##funName() { return varName; }                       \
                                                                               \
public:                                                                        \
  virtual void set##funName(const char *var) { varName = var; }

#define COLOR3_FOCUS_YELLOW ccc3(220, 151, 2)
#define COLOR3_FOCUS_GRAY ccc3(132, 132, 132)
#define COLOR4_FOCUS_YELLOW ccc4(220, 151, 2, 255)
#define COLOR4_FOCUS_GRAY ccc4(132, 132, 132, 255)
#define COLOR3_FOCUS_RED ccc3(183, 52, 52)

#define FONTNAME_NORMAL "Arial"
#define FONTNAME_BOLD "Arial"

#endif /* defined(__awesomeott__gMacro__) */
