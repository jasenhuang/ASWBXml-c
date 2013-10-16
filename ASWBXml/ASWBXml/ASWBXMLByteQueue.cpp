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


#include "ASWBXMLByteQueue.h"

using namespace ASWBXML;

CASWBXMLByteQueue::CASWBXMLByteQueue()
{
    
}
CASWBXMLByteQueue::CASWBXMLByteQueue(unsigned char *bytes , int len)
{
    for (int i = 0 ; i < len; ++i) {
        data.push(bytes[i]);
    }
}
CASWBXMLByteQueue::~ CASWBXMLByteQueue()
{
    
}
bool CASWBXMLByteQueue::Empty()
{
    return data.empty();
}
unsigned char CASWBXMLByteQueue::Dequeue()
{
    unsigned char c = data.front();
    data.pop();
    return c;
}
int CASWBXMLByteQueue::DequeueMultibyteInt()
{
    int iReturn = 0;
    unsigned char singleByte = 0xFF;
    do {
        iReturn <<= 7;
        singleByte = Dequeue();
        iReturn += (int)(singleByte & 0x7F);
    } while (CheckContinuationBit(singleByte));
    return iReturn;
}
bool CASWBXMLByteQueue::CheckContinuationBit(unsigned char byteval)
{
    unsigned char continuationBitmask = 0x80;
    return (continuationBitmask & byteval) != 0;
}
std::string CASWBXMLByteQueue::DequeueString()
{
    std::string strReturn = "";
    unsigned char currentByte = 0x00;
    do {
        // TODO: Improve this handling. We are technically UTF-8, meaning
        // that characters could be more than one byte long. This will fail if we have
        // characters outside of the US-ASCII range
        currentByte = Dequeue();
        if (currentByte != 0x00){
            strReturn += (char)currentByte;
        }
    } while (currentByte != 0x00);
    return strReturn;
}
std::string CASWBXMLByteQueue::DequeueString(int length)
{
    std::string strReturn = "";
    unsigned char currentByte = 0x00;
    for (int i = 0; i < length; i++){
        // TODO: Improve this handling. We are technically UTF-8, meaning
        // that characters could be more than one byte long. This will fail if we have
        // characters outside of the US-ASCII range
        currentByte = Dequeue();
        strReturn += (char)currentByte;
    }
    return strReturn;
}

