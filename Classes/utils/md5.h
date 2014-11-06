/*
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _MD5_H_
#define _MD5_H_ 1

#include <stdint.h>
#include <unistd.h>

#include <string>

namespace ott {
struct MD5Context {
  uint32_t buf[4];
  uint32_t bytes[2];
  uint32_t in[16];
};

class MD5 {
 public:
  MD5();
  ~MD5();

  void append(const void* inBuf, size_t inLen);
  void append(const std::string& str);
  void getDigest(unsigned char digest[16]);
  void getDigest(std::string& digest);

  // 计算给定字符串的md5值
  static std::string getMD5(const std::string& text);

  // 计算指定文件的md5值
  static std::string getFileMD5(const std::string& file);

 private:
  MD5Context m_ctx;
};
}

#endif
