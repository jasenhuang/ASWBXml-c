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

#import "FMWbxml.h"
#include "ASWBXML.h"

@implementation FMWbxml

+(NSData *)xml2wb:(NSString *) xml
{
    ASWBXML::CASWBXML* encoder = new ASWBXML::CASWBXML();
    
    std::string xmlString = [xml UTF8String];
    encoder->LoadXml(xmlString);
    
    unsigned char * bytes = NULL;
    unsigned int byteLen = 0;
    
    encoder->GetBytes(&bytes,&byteLen);
    
    return [NSData dataWithBytes:(const void *)bytes length:byteLen];
}
+(NSString *)wb2xml:(NSData *) bytes
{
    ASWBXML::CASWBXML* decoder = new ASWBXML::CASWBXML();
    
    decoder->LoadBytes((unsigned char*)[bytes bytes] , (int)bytes.length);
    
    /*TiXmlDocument * xmlDoc = new TiXmlDocument();
    xmlDoc->Parse((const char*)decoder->GetXml().c_str(), 0, TIXML_ENCODING_UTF8);
    TiXmlElement * mime = xmlDoc->RootElement()->FirstChildElement("MIME");
    printf("jasen DBG: mime = %s\n" , mime->GetText());*/
    NSString * xml = [NSString stringWithCString:decoder->GetXml().c_str() encoding:NSUTF8StringEncoding];

    delete decoder;
    return xml;

}
@end
