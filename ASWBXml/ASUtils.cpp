/*
 The MIT License (MIT)
 
 Copyright (c) 2013 jasenhuang
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "ASUtils.h"
#include <sstream>

namespace ASUtils {
    std::string LowercaseString(const std::string & str)
    {
        std::string ret;
        ret.resize(str.size());
        std::transform(str.begin(), str.end(), ret.begin(), ::tolower);
        return ret;
    }
    std::string UppercaseString(const std::string & str)
    {
        std::string ret;
        ret.resize(str.size());
        std::transform(str.begin(), str.end(), ret.begin(), ::toupper);
        return ret;
    }
    void Split(const std::string& s, char delim, std::vector<std::string> & elems)
    {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
}
