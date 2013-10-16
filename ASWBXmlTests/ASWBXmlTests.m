//
//  ASWBXmlTests.m
//  ASWBXmlTests
//
//  Created by jasenhuang-iMac on 13-10-14.
//  Copyright (c) 2013年 tencent. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "FMWbxml.h"

@interface ASWBXmlTests : XCTestCase

@end

@implementation ASWBXmlTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample
{
    //XCTFail(@"No implementation for \"%s\"", __PRETTY_FUNCTION__);
    NSString * xml = @"<?xml version=\"1.0\"?><!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\" \"http://www.microsoft.com/\"><SendMail xmlns=\"http://synce.org/formats/airsync_wm5/composemail\"><ClientId>31A04C03-90DE-4291-9629-A647A1BD5D37</ClientId><SaveInSentItems/><MIME>Content-Type: text/plain;\n	charset=gb2312\nContent-Transfer-Encoding: base64\nSubject: Aaaaaaaaas\nFrom: jasenhuang@tencent.com\nMessage-Id: <31A04C03-90DE-4291-9629-A647A1BD5D38@tencent.com>;\nDate: Fri, 11 Oct 2013 16:35:45 +0800\nTo: =?GB2312?Q?jasenhuang_=BB=C6=E8=F2=C9=FA?= <;jasenhuang@tencent.com>;\nMime-Version: 1.0 (1.0)\n\nDQoNCrei19TO0rXEIGlQb2Q=</MIME></SendMail>";
    NSData * bytes = [FMWbxml xml2wb:xml];
    NSString * checkXml = [FMWbxml wb2xml:bytes];
    NSLog(@"jasen DBG: %@" , checkXml);
}

@end
