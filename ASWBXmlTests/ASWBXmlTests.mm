//
//  ASWBXmlTests.m
//  ASWBXmlTests
//
//  Created by jasenhuang-iMac on 12/23/14.
//  Copyright (c) 2014 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>
#include "ASWBXml.h"

@interface ASWBXmlTests : XCTestCase

@end

std::string encode(std::string xmlString)
{
    ASWBXML::CASWBXML* encoder = new ASWBXML::CASWBXML();
    encoder->LoadXml(xmlString);
    unsigned char * bytes = NULL;
    unsigned int byteLen = 0;
    encoder->GetBytes(&bytes,&byteLen);
    return std::string((char*)bytes,byteLen);
}
std::string decode(unsigned char* bytes , unsigned int len)
{
    return ASWBXML::CASWBXML::WB2XML(bytes, len);
}
@implementation ASWBXmlTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    //XCTAssert(YES, @"Pass");
    std::string requestXml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
    requestXml += "<!DOCTYPE ActiveSync PUBLIC \"-//MICROSOFT//DTD ActiveSync//EN\" \"http://www.microsoft.com/\">";
    requestXml += "<Provision xmlns=\"Provision\">";
    requestXml += "<Policies><Policy><PolicyType>MS-EAS-Provisioning-WBXML</PolicyType></Policy></Policies>";
    requestXml += "</Provision>";
    std::string wbxml = encode(requestXml);
    
    requestXml = decode((unsigned char*)wbxml.c_str(), (unsigned int)wbxml.length());
    
    std::cout<<"jasen DBG: "<<requestXml<<std::endl;
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
