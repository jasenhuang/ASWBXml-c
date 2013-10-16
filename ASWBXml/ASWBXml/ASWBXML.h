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

#ifndef __FMWbxml__ASWBXML__
#define __FMWbxml__ASWBXML__

#include <iostream>
#include <vector>
#include "ASWBXMLCodePage.h"
#include "ASWBXMLByteQueue.h"
#include "tinyxml.h"

namespace ASWBXML {
    
    enum GlobalTokens
    {
        SWITCH_PAGE = 0x00,
        END         = 0x01,
        ENTITY      = 0x02,
        STR_I       = 0x03,
        LITERAL     = 0x04,
        EXT_I_0     = 0x40,
        EXT_I_1     = 0x41,
        EXT_I_2     = 0x42,
        PI          = 0x43,
        LITERAL_C   = 0x44,
        EXT_T_0     = 0x80,
        EXT_T_1     = 0x81,
        EXT_T_2     = 0x82,
        STR_T       = 0x83,
        LITERAL_A   = 0x84,
        EXT_0       = 0xC0,
        EXT_1       = 0xC1,
        EXT_2       = 0xC2,
        OPAQUE      = 0xC3,
        LITERAL_AC  = 0xC4
    };
    
    class CASWBXML
    {
    public:
        CASWBXML();
        ~ CASWBXML();
        
        static std::string WB2XML(unsigned char* byteWBXML ,unsigned int len);
        static void XML2WB(std::string& strXML,unsigned char ** bytes ,unsigned int* len);
        
        /*load*/
        void LoadXmlFromFile(std::string &strFilename);
        void LoadXml(std::string& strXML);
        void LoadXml(TiXmlDocument& doc);
        std::string GetXml();
        
        bool LoadBytes(unsigned char * byteWBXML ,unsigned int len);
        void GetBytes(unsigned char ** bytes ,unsigned int* len);
        
    private:
        void EncodeNode(TiXmlElement * node , std::vector<unsigned char> & byteList);
        int GetCodePageByXmlns(std::string& xmlns);
        int GetCodePageByNamespace(std::string& nameSpace);
        bool SetCodePageByXmlns(std::string& xmlns);
        void ParseXmlnsAttributes(TiXmlElement * node);
        
        /*encode*/
        void EncodeString(std::string& value , std::vector<unsigned char> & byteList);
        void EncodeOpaque(std::string& value , std::vector<unsigned char> & byteList);
        void EncodeMultiByteInteger(int value , std::vector<unsigned char> & byteList);
        
        
    protected:
        void InitCodePage();
        void InitAirSyncPage();
        void InitContactsPage();
        void InitEmailPage();
        void InitAirNotifyPage();
        void InitCalendarPage();
        void InitMovePage();
        void InitItemEstimatePage();
        void InitFolderHierarchyPage();
        void InitMeetingResponsePage();
        void InitTaskPage();
        void InitResolveRecipientsPage();
        void InitValidateCertPage();
        void InitContacts2Page();
        void InitPingPage();
        void InitProvisionPage();
        void InitSearchPage();
        void InitGALPage();
        void InitAirSyncBasePage();
        void InitSettingsPage();
        void InitDocumentLibraryPage();
        void InitItemOperationsPage();
        void InitComposeMailPage();
        void InitEmail2Page();
        void InitNotesPage();
        void InitRightsManagementPage();
        
    private:
        TiXmlDocument * xmlDoc;
        std::vector<CASWBXMLCodePage *> codePages;
        int currentCodePage;
        int defaultCodePage;
    };
}


#endif /* defined(__FMWbxml__ASWBXML__) */
