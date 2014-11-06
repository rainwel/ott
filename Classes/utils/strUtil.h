//
//  strUtil.h
//  cloudbox
//
//  Created by Rain on 13-7-31.
//
//

#ifndef cloudbox_strUtil_h
#define cloudbox_strUtil_h

#include <string>
#include "cocos2d.h"
using namespace std;

namespace ott {
typedef struct {
  string key;
  string value;
} Dict;

class strUtil {
 public:
  static strUtil *getInstance();
  bool init();

  vector<std::string> split(string str, string pattern);
  string trim(string str);

  bool replace(std::string &str, const std::string &from,
               const std::string &to);
  string formatTimeStamp(long timeStamp, int iformat);

  string getHeaderByKey(const vector<char> *respHeader, const char *key);

  void logInfo(int idebug, const char *format, ...);
  /*给网络请求参数排序,按参数名来排序
   @params:参数字符串，如：a=1&d=4&s=true&b=test&b=any
   @pattern:第一层分隔字符，如：&
   @separator:第二层分隔字符，如：＝
   @return 排序后的参数字符串，如：a=1&b=any&b=test&d=4&s=true
   */
  string sortParams(string params, string pattern, string separator);
  static bool lessmark(const Dict &s1, const Dict &s2);
  static const char *i2str(int ival);

 private:
  static strUtil *m_pStrUtil;
};
}
#endif
