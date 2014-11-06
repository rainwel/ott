//
//  strUtil.cpp
//  cloudbox
//
//  Created by Rain on 13-7-31.
//
//

#include "strUtil.h"
#include <time.h>
#include <algorithm>
namespace ott {
strUtil *strUtil::m_pStrUtil = NULL;

strUtil *strUtil::getInstance() {
  if (m_pStrUtil == NULL) {
    m_pStrUtil = new strUtil();
    m_pStrUtil->init();
  }
  return m_pStrUtil;
}

bool strUtil::init() { return true; }

string strUtil::trim(string str) {
  string::size_type pos = str.find_first_not_of(' ');
  if (pos == string::npos) {
    return str;
  }
  string::size_type pos2 = str.find_last_not_of(' ');
  if (pos2 != string::npos) {
    return str.substr(pos, pos2 - pos + 1);
  }
  return str.substr(pos);
}

const char *strUtil::i2str(int number) {
  //  // create a stringstream
  //  stringstream ss;
  //  // add number to the stream
  //  ss << number;
  //  // return a string with the contents of the stream
  //  return ss.str().data();
  return "";  // CCString::createWithFormat("%d", number)->getCString();
}

vector<string> strUtil::split(string str, string pattern) {
  string::size_type pos;
  vector<string> result;
  str += pattern;  //扩展字符串以方便操作
  int size = str.size();

  for (int i = 0; i < size; i++) {
    pos = str.find(pattern, i);
    if (pos < size) {
      string s = str.substr(i, pos - i);
      result.push_back(s);
      i = pos + pattern.size() - 1;
    }
  }
  return result;
}

string strUtil::getHeaderByKey(const vector<char> *respHeader,
                               const char *key) {
  string ret = "";
  string strHeaders = string(respHeader->data(), respHeader->size());
  string::size_type pos = strHeaders.find(key);
  if (pos < strHeaders.size()) {
    std::string remain = strHeaders.substr(pos);

    // Rain: Try to find the second one
    std::string::size_type pos2 = remain.find(key, strlen(key));
    if (pos2 < strHeaders.size() && pos2 != std::string::npos) {
      remain = remain.substr(pos2);

      // Rain: Try to find the third one. And stop trying.
      pos2 = remain.find(key, strlen(key));
      if (pos2 < strHeaders.size() && pos2 != std::string::npos) {
        remain = remain.substr(pos2);
      }
    }

    pos = remain.find_first_of("\r\n");
    remain = remain.substr(0, pos);
    ret = remain.substr(remain.find_first_of(":") + 1);
    ret = trim(ret);
  }
  return ret;
}

bool strUtil::replace(std::string &str, const std::string &from,
                      const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos) {
    return false;
  }
  str.replace(start_pos, from.length(), to);
  return true;
}

string strUtil::formatTimeStamp(long timeStamp, int iformat) {
  string strRet = "";
  string strFormat = "%H:%M";
  switch (iformat) {
    case 2: {
      strFormat = "%F %H:%M";
    } break;
    default:
      break;
  }
  //  struct tm *ptm = localtime(&timeStamp);
  //  char szBuf[64] = {0};
  //  strftime(szBuf, 63, strFormat.c_str(), ptm);
  //  strRet = szBuf;

  struct tm *timeinfo;
  char buffer[80];

  time(&timeStamp);
  timeinfo = localtime(&timeStamp);

  strftime(buffer, 80, strFormat.c_str(), timeinfo);
  //  puts(buffer);
  strRet = buffer;
  return strRet;
}

/*给网络请求参数排序,按参数名来排序
 @params:参数字符串，如：a=1&d=4&s=true&b=test&b=any
 @pattern:第一层分隔字符，如：&
 @separator:第二层分隔字符，如：＝
 @return 排序后的参数字符串，如：a=1&b=any&b=test&d=4&s=true
 */
string strUtil::sortParams(string params, string pattern, string separator) {
  if (params.length() <= 0) {
    return "";
  }
  vector<string> paramsVector = this->split(params, pattern);
  if (paramsVector.empty()) {
    return "";
  }
  vector<Dict> results;
  string paramStr = "";
  for (int i = 0; i < paramsVector.size(); i++) {
    string param = paramsVector[i];
    if (param.length() <= 0) {
      continue;
    }
    vector<string> member = this->split(param, separator);
    if (member.empty()) {
      continue;
    }
    Dict dict;
    if (member.size() == 2) {
      dict.key = member[0];
      dict.value = member[1];
      results.push_back(dict);
    }
  }
  if (results.size() > 0) {
    sort(results.begin(), results.end(), strUtil::lessmark);
    for (int j = 0; j < results.size(); j++) {
      Dict temp = results[j];
      paramStr.append(temp.key);
      paramStr.append(separator);
      paramStr.append(temp.value);
      if (j < results.size() - 1) {
        paramStr.append(pattern);
      }
    }
  }
  logInfo(1, "strUtil paramStr = %s", paramStr.c_str());
  return paramStr;
}

bool strUtil::lessmark(const Dict &s1, const Dict &s2) {
  return s1.key.compare(s2.key) < 0;
}

void strUtil::logInfo(int idebug, const char *format, ...) {
  if (idebug != 1) {
    return;
  }
  va_list args;
  va_start(args, format);

  char buf[cocos2d::MAX_LOG_LENGTH];

  vsnprintf(buf, cocos2d::MAX_LOG_LENGTH - 3, format, args);
  strcat(buf, "\n");

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
  __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);

#else
  // Linux, Mac, iOS, etc
  fprintf(stdout, "cocos2d: %s", buf);
  fflush(stdout);
#endif

  va_end(args);
}
}
