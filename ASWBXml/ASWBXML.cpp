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

#include "ASWBXML.h"
#include "ASUtils.h"

const unsigned char versionByte = 0x03;
const unsigned char publicIdentifierByte = 0x01;
const unsigned char characterSetByte = 0x6A;     // UTF-8
const unsigned char stringTableLengthByte = 0x00;

using namespace ASWBXML;

CASWBXML::CASWBXML()
{
    xmlDoc = NULL;
    currentCodePage = 0;
    defaultCodePage = -1;
    InitCodePage();
}
CASWBXML::~CASWBXML()
{
    if (NULL != xmlDoc) {
        delete xmlDoc;
    }
    for (std::vector<CASWBXMLCodePage *>::const_iterator it=codePages.begin(); it != codePages.end(); ++it) {
        delete *it;
    }
}

void CASWBXML::InitCodePage()
{
    InitAirSyncPage();
    InitContactsPage();
    InitEmailPage();
    InitAirNotifyPage();
    InitCalendarPage();
    InitMovePage();
    InitItemEstimatePage();
    InitFolderHierarchyPage();
    InitMeetingResponsePage();
    InitTaskPage();
    InitResolveRecipientsPage();
    InitValidateCertPage();
    InitContacts2Page();
    InitPingPage();
    InitProvisionPage();
    InitSearchPage();
    InitGALPage();
    InitAirSyncBasePage();
    InitSettingsPage();
    InitDocumentLibraryPage();
    InitItemOperationsPage();
    InitComposeMailPage();
    InitEmail2Page();
    InitNotesPage();
    InitRightsManagementPage();
}
void CASWBXML::InitAirSyncPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    
    page->strNamespace = "AirSync";
    page->strXmlns = "airsync";
    
    page->AddToken(0x05, "Sync");
    page->AddToken(0x06, "Responses");
    page->AddToken(0x07, "Add");
    page->AddToken(0x08, "Change");
    page->AddToken(0x09, "Delete");
    page->AddToken(0x0A, "Fetch");
    page->AddToken(0x0B, "SyncKey");
    page->AddToken(0x0C, "ClientId");
    page->AddToken(0x0D, "ServerId");
    page->AddToken(0x0E, "Status");
    page->AddToken(0x0F, "Collection");
    page->AddToken(0x10, "Class");
    page->AddToken(0x12, "CollectionId");
    page->AddToken(0x13, "GetChanges");
    page->AddToken(0x14, "MoreAvailable");
    page->AddToken(0x15, "WindowSize");
    page->AddToken(0x16, "Commands");
    page->AddToken(0x17, "Options");
    page->AddToken(0x18, "FilterType");
    page->AddToken(0x1B, "Conflict");
    page->AddToken(0x1C, "Collections");
    page->AddToken(0x1D, "ApplicationData");
    page->AddToken(0x1E, "DeletesAsMoves");
    page->AddToken(0x20, "Supported");
    page->AddToken(0x21, "SoftDelete");
    page->AddToken(0x22, "MIMESupport");
    page->AddToken(0x23, "MIMETruncation");
    page->AddToken(0x24, "Wait");
    page->AddToken(0x25, "Limit");
    page->AddToken(0x26, "Partial");
    page->AddToken(0x27, "ConversationMode");
    page->AddToken(0x28, "MaxItems");
    page->AddToken(0x29, "HeartbeatInterval");
    codePages.push_back(page);
}
void CASWBXML::InitContactsPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Contacts";
    page->strXmlns = "contacts";
    
    page->AddToken(0x05, "Anniversary");
    page->AddToken(0x06, "AssistantName");
    page->AddToken(0x07, "AssistantPhoneNumber");
    page->AddToken(0x08, "Birthday");
    page->AddToken(0x0C, "Business2PhoneNumber");
    page->AddToken(0x0D, "BusinessAddressCity");
    page->AddToken(0x0E, "BusinessAddressCountry");
    page->AddToken(0x0F, "BusinessAddressPostalCode");
    page->AddToken(0x10, "BusinessAddressState");
    page->AddToken(0x11, "BusinessAddressStreet");
    page->AddToken(0x12, "BusinessFaxNumber");
    page->AddToken(0x13, "BusinessPhoneNumber");
    page->AddToken(0x14, "CarPhoneNumber");
    page->AddToken(0x15, "Categories");
    page->AddToken(0x16, "Category");
    page->AddToken(0x17, "Children");
    page->AddToken(0x18, "Child");
    page->AddToken(0x19, "CompanyName");
    page->AddToken(0x1A, "Department");
    page->AddToken(0x1B, "Email1Address");
    page->AddToken(0x1C, "Email2Address");
    page->AddToken(0x1D, "Email3Address");
    page->AddToken(0x1E, "FileAs");
    page->AddToken(0x1F, "FirstName");
    page->AddToken(0x20, "Home2PhoneNumber");
    page->AddToken(0x21, "HomeAddressCity");
    page->AddToken(0x22, "HomeAddressCountry");
    page->AddToken(0x23, "HomeAddressPostalCode");
    page->AddToken(0x24, "HomeAddressState");
    page->AddToken(0x25, "HomeAddressStreet");
    page->AddToken(0x26, "HomeFaxNumber");
    page->AddToken(0x27, "HomePhoneNumber");
    page->AddToken(0x28, "JobTitle");
    page->AddToken(0x29, "LastName");
    page->AddToken(0x2A, "MiddleName");
    page->AddToken(0x2B, "MobilePhoneNumber");
    page->AddToken(0x2C, "OfficeLocation");
    page->AddToken(0x2D, "OtherAddressCity");
    page->AddToken(0x2E, "OtherAddressCountry");
    page->AddToken(0x2F, "OtherAddressPostalCode");
    page->AddToken(0x30, "OtherAddressState");
    page->AddToken(0x31, "OtherAddressStreet");
    page->AddToken(0x32, "PagerNumber");
    page->AddToken(0x33, "RadioPhoneNumber");
    page->AddToken(0x34, "Spouse");
    page->AddToken(0x35, "Suffix");
    page->AddToken(0x36, "Title");
    page->AddToken(0x37, "WebPage");
    page->AddToken(0x38, "YomiCompanyName");
    page->AddToken(0x39, "YomiFirstName");
    page->AddToken(0x3A, "YomiLastName");
    page->AddToken(0x3C, "Picture");
    page->AddToken(0x3D, "Alias");
    page->AddToken(0x3E, "WeightedRank");
    codePages.push_back(page);
}
void CASWBXML::InitEmailPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Email";
    page->strXmlns = "email";
    
    page->AddToken(0x0F, "DateReceived");
    page->AddToken(0x11, "DisplayTo");
    page->AddToken(0x12, "Importance");
    page->AddToken(0x13, "MessageClass");
    page->AddToken(0x14, "Subject");
    page->AddToken(0x15, "Read");
    page->AddToken(0x16, "To");
    page->AddToken(0x17, "Cc");
    page->AddToken(0x18, "From");
    page->AddToken(0x19, "ReplyTo");
    page->AddToken(0x1A, "AllDayEvent");
    page->AddToken(0x1B, "Categories");
    page->AddToken(0x1C, "Category");
    page->AddToken(0x1D, "DtStamp");
    page->AddToken(0x1E, "EndTime");
    page->AddToken(0x1F, "InstanceType");
    page->AddToken(0x20, "BusyStatus");
    page->AddToken(0x21, "Location");
    page->AddToken(0x22, "MeetingRequest");
    page->AddToken(0x23, "Organizer");
    page->AddToken(0x24, "RecurrenceId");
    page->AddToken(0x25, "Reminder");
    page->AddToken(0x26, "ResponseRequested");
    page->AddToken(0x27, "Recurrences");
    page->AddToken(0x28, "Recurrence");
    page->AddToken(0x29, "Type");
    page->AddToken(0x2A, "Until");
    page->AddToken(0x2B, "Occurrences");
    page->AddToken(0x2C, "Interval");
    page->AddToken(0x2D, "DayOfWeek");
    page->AddToken(0x2E, "DayOfMonth");
    page->AddToken(0x2F, "WeekOfMonth");
    page->AddToken(0x30, "MonthOfYear");
    page->AddToken(0x31, "StartTime");
    page->AddToken(0x32, "Sensitivity");
    page->AddToken(0x33, "TimeZone");
    page->AddToken(0x34, "GlobalObjId");
    page->AddToken(0x35, "ThreadTopic");
    page->AddToken(0x39, "InternetCPID");
    page->AddToken(0x3A, "Flag");
    page->AddToken(0x3B, "Status");
    page->AddToken(0x3C, "ContentClass");
    page->AddToken(0x3D, "FlagType");
    page->AddToken(0x3E, "CompleteTime");
    page->AddToken(0x3F, "DisallowNewTimeProposal");
    codePages.push_back(page);
}
void CASWBXML::InitAirNotifyPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "";
    page->strXmlns = "";
    codePages.push_back(page);
}
void CASWBXML::InitCalendarPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Calendar";
    page->strXmlns = "calendar";
    
    page->AddToken(0x05, "TimeZone");
    page->AddToken(0x06, "AllDayEvent");
    page->AddToken(0x07, "Attendees");
    page->AddToken(0x08, "Attendee");
    page->AddToken(0x09, "Email");
    page->AddToken(0x0A, "Name");
    page->AddToken(0x0D, "BusyStatus");
    page->AddToken(0x0E, "Categories");
    page->AddToken(0x0F, "Category");
    page->AddToken(0x11, "DtStamp");
    page->AddToken(0x12, "EndTime");
    page->AddToken(0x13, "Exception");
    page->AddToken(0x14, "Exceptions");
    page->AddToken(0x15, "Deleted");
    page->AddToken(0x16, "ExceptionStartTime");
    page->AddToken(0x17, "Location");
    page->AddToken(0x18, "MeetingStatus");
    page->AddToken(0x19, "OrganizerEmail");
    page->AddToken(0x1A, "OrganizerName");
    page->AddToken(0x1B, "Recurrence");
    page->AddToken(0x1C, "Type");
    page->AddToken(0x1D, "Until");
    page->AddToken(0x1E, "Occurrences");
    page->AddToken(0x1F, "Interval");
    page->AddToken(0x20, "DayOfWeek");
    page->AddToken(0x21, "DayOfMonth");
    page->AddToken(0x22, "WeekOfMonth");
    page->AddToken(0x23, "MonthOfYear");
    page->AddToken(0x24, "Reminder");
    page->AddToken(0x25, "Sensitivity");
    page->AddToken(0x26, "Subject");
    page->AddToken(0x27, "StartTime");
    page->AddToken(0x28, "UID");
    page->AddToken(0x29, "AttendeeStatus");
    page->AddToken(0x2A, "AttendeeType");
    page->AddToken(0x33, "DisallowNewTimeProposal");
    page->AddToken(0x34, "ResponseRequested");
    page->AddToken(0x35, "AppointmentReplyTime");
    page->AddToken(0x36, "ResponseType");
    page->AddToken(0x37, "CalendarType");
    page->AddToken(0x38, "IsLeapMonth");
    page->AddToken(0x39, "FirstDayOfWeek");
    page->AddToken(0x3A, "OnlineMeetingConfLink");
    page->AddToken(0x3B, "OnlineMeetingExternalLink");
    codePages.push_back(page);
}
void CASWBXML::InitMovePage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Move";
    page->strXmlns = "move";
    
    page->AddToken(0x05, "MoveItems");
    page->AddToken(0x06, "Move");
    page->AddToken(0x07, "SrcMsgId");
    page->AddToken(0x08, "SrcFldId");
    page->AddToken(0x09, "DstFldId");
    page->AddToken(0x0A, "Response");
    page->AddToken(0x0B, "Status");
    page->AddToken(0x0C, "DstMsgId");
    codePages.push_back(page);
}
void CASWBXML::InitItemEstimatePage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "GetItemEstimate";
    page->strXmlns = "getitemestimate";
    
    page->AddToken(0x05, "GetItemEstimate");
    page->AddToken(0x06, "Version");
    page->AddToken(0x07, "Collections");
    page->AddToken(0x08, "Collection");
    page->AddToken(0x09, "Class");
    page->AddToken(0x0A, "CollectionId");
    page->AddToken(0x0B, "DateTime");
    page->AddToken(0x0C, "Estimate");
    page->AddToken(0x0D, "Response");
    page->AddToken(0x0E, "Status");
    codePages.push_back(page);
}
void CASWBXML::InitFolderHierarchyPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "FolderHierarchy";
    page->strXmlns = "folderhierarchy";
    
    page->AddToken(0x07, "DisplayName");
    page->AddToken(0x08, "ServerId");
    page->AddToken(0x09, "ParentId");
    page->AddToken(0x0A, "Type");
    page->AddToken(0x0C, "Status");
    page->AddToken(0x0E, "Changes");
    page->AddToken(0x0F, "Add");
    page->AddToken(0x10, "Delete");
    page->AddToken(0x11, "Update");
    page->AddToken(0x12, "SyncKey");
    page->AddToken(0x13, "FolderCreate");
    page->AddToken(0x14, "FolderDelete");
    page->AddToken(0x15, "FolderUpdate");
    page->AddToken(0x16, "FolderSync");
    page->AddToken(0x17, "Count");
    codePages.push_back(page);
}
void CASWBXML::InitMeetingResponsePage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "MeetingResponse";
    page->strXmlns = "meetingresponse";
    
    page->AddToken(0x05, "CalendarId");
    page->AddToken(0x06, "CollectionId");
    page->AddToken(0x07, "MeetingResponse");
    page->AddToken(0x08, "RequestId");
    page->AddToken(0x09, "Request");
    page->AddToken(0x0A, "Result");
    page->AddToken(0x0B, "Status");
    page->AddToken(0x0C, "UserResponse");
    page->AddToken(0x0E, "InstanceId");
    codePages.push_back(page);
}
void CASWBXML::InitTaskPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Tasks";
    page->strXmlns = "tasks";
    
    page->AddToken(0x08, "Categories");
    page->AddToken(0x09, "Category");
    page->AddToken(0x0A, "Complete");
    page->AddToken(0x0B, "DateCompleted");
    page->AddToken(0x0C, "DueDate");
    page->AddToken(0x0D, "UtcDueDate");
    page->AddToken(0x0E, "Importance");
    page->AddToken(0x0F, "Recurrence");
    page->AddToken(0x10, "Type");
    page->AddToken(0x11, "Start");
    page->AddToken(0x12, "Until");
    page->AddToken(0x13, "Occurrences");
    page->AddToken(0x14, "Interval");
    page->AddToken(0x15, "DayOfMonth");
    page->AddToken(0x16, "DayOfWeek");
    page->AddToken(0x17, "WeekOfMonth");
    page->AddToken(0x18, "MonthOfYear");
    page->AddToken(0x19, "Regenerate");
    page->AddToken(0x1A, "DeadOccur");
    page->AddToken(0x1B, "ReminderSet");
    page->AddToken(0x1C, "ReminderTime");
    page->AddToken(0x1D, "Sensitivity");
    page->AddToken(0x1E, "StartDate");
    page->AddToken(0x1F, "UtcStartDate");
    page->AddToken(0x20, "Subject");
    page->AddToken(0x22, "OrdinalDate");
    page->AddToken(0x23, "SubOrdinalDate");
    page->AddToken(0x24, "CalendarType");
    page->AddToken(0x25, "IsLeapMonth");
    page->AddToken(0x26, "FirstDayOfWeek");
    codePages.push_back(page);
}
void CASWBXML::InitResolveRecipientsPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "ResolveRecipients";
    page->strXmlns = "resolverecipients";
    
    page->AddToken(0x05, "ResolveRecipients");
    page->AddToken(0x06, "Response");
    page->AddToken(0x07, "Status");
    page->AddToken(0x08, "Type");
    page->AddToken(0x09, "Recipient");
    page->AddToken(0x0A, "DisplayName");
    page->AddToken(0x0B, "EmailAddress");
    page->AddToken(0x0C, "Certificates");
    page->AddToken(0x0D, "Certificate");
    page->AddToken(0x0E, "MiniCertificate");
    page->AddToken(0x0F, "Options");
    page->AddToken(0x10, "To");
    page->AddToken(0x11, "CertificateRetrieval");
    page->AddToken(0x12, "RecipientCount");
    page->AddToken(0x13, "MaxCertificates");
    page->AddToken(0x14, "MaxAmbiguousRecipients");
    page->AddToken(0x15, "CertificateCount");
    page->AddToken(0x16, "Availability");
    page->AddToken(0x17, "StartTime");
    page->AddToken(0x18, "EndTime");
    page->AddToken(0x19, "MergedFreeBusy");
    page->AddToken(0x1A, "Picture");
    page->AddToken(0x1B, "MaxSize");
    page->AddToken(0x1C, "Data");
    page->AddToken(0x1D, "MaxPictures");
    codePages.push_back(page);
}
void CASWBXML::InitValidateCertPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "ValidateCert";
    page->strXmlns = "validatecert";
    
    page->AddToken(0x05, "ValidateCert");
    page->AddToken(0x06, "Certificates");
    page->AddToken(0x07, "Certificate");
    page->AddToken(0x08, "CertificateChain");
    page->AddToken(0x09, "CheckCRL");
    page->AddToken(0x0A, "Status");
    codePages.push_back(page);
}
void CASWBXML::InitContacts2Page()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Contacts2";
    page->strXmlns = "contacts2";
    
    page->AddToken(0x05, "CustomerId");
    page->AddToken(0x06, "GovernmentId");
    page->AddToken(0x07, "IMAddress");
    page->AddToken(0x08, "IMAddress2");
    page->AddToken(0x09, "IMAddress3");
    page->AddToken(0x0A, "ManagerName");
    page->AddToken(0x0B, "CompanyMainPhone");
    page->AddToken(0x0C, "AccountName");
    page->AddToken(0x0D, "NickName");
    page->AddToken(0x0E, "MMS");
    codePages.push_back(page);
}
void CASWBXML::InitPingPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Ping";
    page->strXmlns = "ping";
    
    page->AddToken(0x05, "Ping");
    page->AddToken(0x06, "AutdState");  // Per MS-ASWBXML, this tag is not used by protocol
    page->AddToken(0x07, "Status");
    page->AddToken(0x08, "HeartbeatInterval");
    page->AddToken(0x09, "Folders");
    page->AddToken(0x0A, "Folder");
    page->AddToken(0x0B, "Id");
    page->AddToken(0x0C, "Class");
    page->AddToken(0x0D, "MaxFolders");
    codePages.push_back(page);
}
void CASWBXML::InitProvisionPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Provision";
    page->strXmlns = "provision";
    
    page->AddToken(0x05, "Provision");
    page->AddToken(0x06, "Policies");
    page->AddToken(0x07, "Policy");
    page->AddToken(0x08, "PolicyType");
    page->AddToken(0x09, "PolicyKey");
    page->AddToken(0x0A, "Data");
    page->AddToken(0x0B, "Status");
    page->AddToken(0x0C, "RemoteWipe");
    page->AddToken(0x0D, "EASProvisionDoc");
    page->AddToken(0x0E, "DevicePasswordEnabled");
    page->AddToken(0x0F, "AlphanumericDevicePasswordRequired");
    page->AddToken(0x10, "RequireStorageCardEncryption");
    page->AddToken(0x11, "PasswordRecoveryEnabled");
    page->AddToken(0x13, "AttachmentsEnabled");
    page->AddToken(0x14, "MinDevicePasswordLength");
    page->AddToken(0x15, "MaxInactivityTimeDeviceLock");
    page->AddToken(0x16, "MaxDevicePasswordFailedAttempts");
    page->AddToken(0x17, "MaxAttachmentSize");
    page->AddToken(0x18, "AllowSimpleDevicePassword");
    page->AddToken(0x19, "DevicePasswordExpiration");
    page->AddToken(0x1A, "DevicePasswordHistory");
    page->AddToken(0x1B, "AllowStorageCard");
    page->AddToken(0x1C, "AllowCamera");
    page->AddToken(0x1D, "RequireDeviceEncryption");
    page->AddToken(0x1E, "AllowUnsignedApplications");
    page->AddToken(0x1F, "AllowUnsignedInstallationPackages");
    page->AddToken(0x20, "MinDevicePasswordComplexCharacters");
    page->AddToken(0x21, "AllowWiFi");
    page->AddToken(0x22, "AllowTextMessaging");
    page->AddToken(0x23, "AllowPOPIMAPEmail");
    page->AddToken(0x24, "AllowBluetooth");
    page->AddToken(0x25, "AllowIrDA");
    page->AddToken(0x26, "RequireManualSyncWhenRoaming");
    page->AddToken(0x27, "AllowDesktopSync");
    page->AddToken(0x28, "MaxCalendarAgeFilter");
    page->AddToken(0x29, "AllowHTMLEmail");
    page->AddToken(0x2A, "MaxEmailAgeFilter");
    page->AddToken(0x2B, "MaxEmailBodyTruncationSize");
    page->AddToken(0x2C, "MaxEmailHTMLBodyTruncationSize");
    page->AddToken(0x2D, "RequireSignedSMIMEMessages");
    page->AddToken(0x2E, "RequireEncryptedSMIMEMessages");
    page->AddToken(0x2F, "RequireSignedSMIMEAlgorithm");
    page->AddToken(0x30, "RequireEncryptionSMIMEAlgorithm");
    page->AddToken(0x31, "AllowSMIMEEncryptionAlgorithmNegotiation");
    page->AddToken(0x32, "AllowSMIMESoftCerts");
    page->AddToken(0x33, "AllowBrowser");
    page->AddToken(0x34, "AllowConsumerEmail");
    page->AddToken(0x35, "AllowRemoteDesktop");
    page->AddToken(0x36, "AllowInternetSharing");
    page->AddToken(0x37, "UnapprovedInROMApplicationList");
    page->AddToken(0x38, "ApplicationName");
    page->AddToken(0x39, "ApprovedApplicationList");
    page->AddToken(0x3A, "Hash");
    codePages.push_back(page);
}
void CASWBXML::InitSearchPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Search";
    page->strXmlns = "search";
    
    page->AddToken(0x05, "Search");
    page->AddToken(0x07, "Store");
    page->AddToken(0x08, "Name");
    page->AddToken(0x09, "Query");
    page->AddToken(0x0A, "Options");
    page->AddToken(0x0B, "Range");
    page->AddToken(0x0C, "Status");
    page->AddToken(0x0D, "Response");
    page->AddToken(0x0E, "Result");
    page->AddToken(0x0F, "Properties");
    page->AddToken(0x10, "Total");
    page->AddToken(0x11, "EqualTo");
    page->AddToken(0x12, "Value");
    page->AddToken(0x13, "And");
    page->AddToken(0x14, "Or");
    page->AddToken(0x15, "FreeText");
    page->AddToken(0x17, "DeepTraversal");
    page->AddToken(0x18, "LongId");
    page->AddToken(0x19, "RebuildResults");
    page->AddToken(0x1A, "LessThan");
    page->AddToken(0x1B, "GreaterThan");
    page->AddToken(0x1E, "UserName");
    page->AddToken(0x1F, "Password");
    page->AddToken(0x20, "ConversationId");
    page->AddToken(0x21, "Picture");
    page->AddToken(0x22, "MaxSize");
    page->AddToken(0x23, "MaxPictures");
    codePages.push_back(page);
}
void CASWBXML::InitGALPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "GAL";
    page->strXmlns = "gal";
    
    page->AddToken(0x05, "DisplayName");
    page->AddToken(0x06, "Phone");
    page->AddToken(0x07, "Office");
    page->AddToken(0x08, "Title");
    page->AddToken(0x09, "Company");
    page->AddToken(0x0A, "Alias");
    page->AddToken(0x0B, "FirstName");
    page->AddToken(0x0C, "LastName");
    page->AddToken(0x0D, "HomePhone");
    page->AddToken(0x0E, "MobilePhone");
    page->AddToken(0x0F, "EmailAddress");
    page->AddToken(0x10, "Picture");
    page->AddToken(0x11, "Status");
    page->AddToken(0x12, "Data");
    codePages.push_back(page);
}
void CASWBXML::InitAirSyncBasePage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "AirSyncBase";
    page->strXmlns = "airsyncbase";
    
    page->AddToken(0x05, "BodyPreference");
    page->AddToken(0x06, "Type");
    page->AddToken(0x07, "TruncationSize");
    page->AddToken(0x08, "AllOrNone");
    page->AddToken(0x0A, "Body");
    page->AddToken(0x0B, "Data");
    page->AddToken(0x0C, "EstimatedDataSize");
    page->AddToken(0x0D, "Truncated");
    page->AddToken(0x0E, "Attachments");
    page->AddToken(0x0F, "Attachment");
    page->AddToken(0x10, "DisplayName");
    page->AddToken(0x11, "FileReference");
    page->AddToken(0x12, "Method");
    page->AddToken(0x13, "ContentId");
    page->AddToken(0x14, "ContentLocation");
    page->AddToken(0x15, "IsInline");
    page->AddToken(0x16, "NativeBodyType");
    page->AddToken(0x17, "ContentType");
    page->AddToken(0x18, "Preview");
    page->AddToken(0x19, "BodyPartPreference");
    page->AddToken(0x1A, "BodyPart");
    page->AddToken(0x1B, "Status");
    codePages.push_back(page);
}
void CASWBXML::InitSettingsPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Settings";
    page->strXmlns = "settings";
    
    page->AddToken(0x05, "Settings");
    page->AddToken(0x06, "Status");
    page->AddToken(0x07, "Get");
    page->AddToken(0x08, "Set");
    page->AddToken(0x09, "Oof");
    page->AddToken(0x0A, "OofState");
    page->AddToken(0x0B, "StartTime");
    page->AddToken(0x0C, "EndTime");
    page->AddToken(0x0D, "OofMessage");
    page->AddToken(0x0E, "AppliesToInternal");
    page->AddToken(0x0F, "AppliesToExternalKnown");
    page->AddToken(0x10, "AppliesToExternalUnknown");
    page->AddToken(0x11, "Enabled");
    page->AddToken(0x12, "ReplyMessage");
    page->AddToken(0x13, "BodyType");
    page->AddToken(0x14, "DevicePassword");
    page->AddToken(0x15, "Password");
    page->AddToken(0x16, "DeviceInformation");
    page->AddToken(0x17, "Model");
    page->AddToken(0x18, "IMEI");
    page->AddToken(0x19, "FriendlyName");
    page->AddToken(0x1A, "OS");
    page->AddToken(0x1B, "OSLanguage");
    page->AddToken(0x1C, "PhoneNumber");
    page->AddToken(0x1D, "UserInformation");
    page->AddToken(0x1E, "EmailAddresses");
    page->AddToken(0x1F, "SMTPAddress");
    page->AddToken(0x20, "UserAgent");
    page->AddToken(0x21, "EnableOutboundSMS");
    page->AddToken(0x22, "MobileOperator");
    page->AddToken(0x23, "PrimarySmtpAddress");
    page->AddToken(0x24, "Accounts");
    page->AddToken(0x25, "Account");
    page->AddToken(0x26, "AccountId");
    page->AddToken(0x27, "AccountName");
    page->AddToken(0x28, "UserDisplayName");
    page->AddToken(0x29, "SendDisabled");
    page->AddToken(0x2B, "RightsManagementInformation");
    codePages.push_back(page);
}
void CASWBXML::InitDocumentLibraryPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "DocumentLibrary";
    page->strXmlns = "documentlibrary";
    
    page->AddToken(0x05, "LinkId");
    page->AddToken(0x06, "DisplayName");
    page->AddToken(0x07, "IsFolder");
    page->AddToken(0x08, "CreationDate");
    page->AddToken(0x09, "LastModifiedDate");
    page->AddToken(0x0A, "IsHidden");
    page->AddToken(0x0B, "ContentLength");
    page->AddToken(0x0C, "ContentType");
    codePages.push_back(page);
}
void CASWBXML::InitItemOperationsPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "ItemOperations";
    page->strXmlns = "itemoperations";
    
    page->AddToken(0x05, "ItemOperations");
    page->AddToken(0x06, "Fetch");
    page->AddToken(0x07, "Store");
    page->AddToken(0x08, "Options");
    page->AddToken(0x09, "Range");
    page->AddToken(0x0A, "Total");
    page->AddToken(0x0B, "Properties");
    page->AddToken(0x0C, "Data");
    page->AddToken(0x0D, "Status");
    page->AddToken(0x0E, "Response");
    page->AddToken(0x0F, "Version");
    page->AddToken(0x10, "Schema");
    page->AddToken(0x11, "Part");
    page->AddToken(0x12, "EmptyFolderContents");
    page->AddToken(0x13, "DeleteSubFolders");
    page->AddToken(0x14, "UserName");
    page->AddToken(0x15, "Password");
    page->AddToken(0x16, "Move");
    page->AddToken(0x17, "DstFldId");
    page->AddToken(0x18, "ConversationId");
    page->AddToken(0x19, "MoveAlways");
    codePages.push_back(page);
}
void CASWBXML::InitComposeMailPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "ComposeMail";
    page->strXmlns = "composemail";
    
    page->AddToken(0x05, "SendMail");
    page->AddToken(0x06, "SmartForward");
    page->AddToken(0x07, "SmartReply");
    page->AddToken(0x08, "SaveInSentItems");
    page->AddToken(0x09, "ReplaceMime");
    page->AddToken(0x0B, "Source");
    page->AddToken(0x0C, "FolderId");
    page->AddToken(0x0D, "ItemId");
    page->AddToken(0x0E, "LongId");
    page->AddToken(0x0F, "InstanceId");
    page->AddToken(0x10, "MIME");//MIME 大写
    page->AddToken(0x11, "ClientId");
    page->AddToken(0x12, "Status");
    page->AddToken(0x13, "AccountId");
    codePages.push_back(page);
}
void CASWBXML::InitEmail2Page()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Email2";
    page->strXmlns = "email2";
    
    page->AddToken(0x05, "UmCallerID");
    page->AddToken(0x06, "UmUserNotes");
    page->AddToken(0x07, "UmAttDuration");
    page->AddToken(0x08, "UmAttOrder");
    page->AddToken(0x09, "ConversationId");
    page->AddToken(0x0A, "ConversationIndex");
    page->AddToken(0x0B, "LastVerbExecuted");
    page->AddToken(0x0C, "LastVerbExecutionTime");
    page->AddToken(0x0D, "ReceivedAsBcc");
    page->AddToken(0x0E, "Sender");
    page->AddToken(0x0F, "CalendarType");
    page->AddToken(0x10, "IsLeapMonth");
    page->AddToken(0x11, "AccountId");
    page->AddToken(0x12, "FirstDayOfWeek");
    page->AddToken(0x13, "MeetingMessageType");
    codePages.push_back(page);
}
void CASWBXML::InitNotesPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "Notes";
    page->strXmlns = "notes";
    
    page->AddToken(0x05, "Subject");
    page->AddToken(0x06, "MessageClass");
    page->AddToken(0x07, "LastModifiedDate");
    page->AddToken(0x08, "Categories");
    page->AddToken(0x09, "Category");
    codePages.push_back(page);
}
void CASWBXML::InitRightsManagementPage()
{
    CASWBXMLCodePage * page = new CASWBXMLCodePage();
    page->strNamespace = "RightsManagement";
    page->strXmlns = "rightsmanagement";
    
    page->AddToken(0x05, "RightsManagementSupport");
    page->AddToken(0x06, "RightsManagementTemplates");
    page->AddToken(0x07, "RightsManagementTemplate");
    page->AddToken(0x08, "RightsManagementLicense");
    page->AddToken(0x09, "EditAllowed");
    page->AddToken(0x0A, "ReplyAllowed");
    page->AddToken(0x0B, "ReplyAllAllowed");
    page->AddToken(0x0C, "ForwardAllowed");
    page->AddToken(0x0D, "ModifyRecipientsAllowed");
    page->AddToken(0x0E, "ExtractAllowed");
    page->AddToken(0x0F, "PrintAllowed");
    page->AddToken(0x10, "ExportAllowed");
    page->AddToken(0x11, "ProgrammaticAccessAllowed");
    page->AddToken(0x12, "Owner");
    page->AddToken(0x13, "ContentExpiryDate");
    page->AddToken(0x14, "TemplateID");
    page->AddToken(0x15, "TemplateName");
    page->AddToken(0x16, "TemplateDescription");
    page->AddToken(0x17, "ContentOwner");
    page->AddToken(0x18, "RemoveRightsManagementDistribution");
    codePages.push_back(page);
}
std::string CASWBXML::WB2XML(unsigned char* byteWBXML ,unsigned int len)
{
    ASWBXML::CASWBXML * decoder = new ASWBXML::CASWBXML();
    decoder->LoadBytes(byteWBXML, len);
    std::string xml = decoder->GetXml();
    delete decoder;
    return xml;
}
void CASWBXML::XML2WB(std::string& strXML,unsigned char ** bytes ,unsigned int* len)
{
    ASWBXML::CASWBXML * encoder = new ASWBXML::CASWBXML();
    encoder->LoadXml(strXML);
    encoder->GetBytes(bytes, len);
    delete encoder;
}
void CASWBXML::LoadXmlFromFile(std::string &strFilename)
{
    if (NULL != xmlDoc){
        delete xmlDoc;
    }
    xmlDoc = new TiXmlDocument();
    xmlDoc->LoadFile(strFilename.c_str());
}
void CASWBXML::LoadXml(std::string& strXML)
{
    if (NULL != xmlDoc){
        delete xmlDoc;
    }
    xmlDoc = new TiXmlDocument();
    xmlDoc->Parse((const char*)strXML.c_str(), 0, TIXML_ENCODING_UTF8);
//    xmlDoc->Print();
}
void CASWBXML::LoadXml(TiXmlDocument& doc)
{
    if (NULL != xmlDoc){
        delete xmlDoc;
    }
    xmlDoc = new TiXmlDocument(doc);
//    xmlDoc->Print();
}
std::string CASWBXML::GetXml()
{
    std::string xml = "";
    if (xmlDoc != NULL){
        //xmlDoc->Print();
        TiXmlPrinter printer;
        printer.SetIndent("\t");
        xmlDoc->Accept(&printer);
        xml = printer.CStr();
    }
    return xml;
}
bool CASWBXML::LoadBytes(unsigned char * byteWBXML ,unsigned int len)
{
    if (NULL != xmlDoc){
        delete xmlDoc;
    }
    xmlDoc = new TiXmlDocument();
    CASWBXMLByteQueue * bytes = new CASWBXMLByteQueue(byteWBXML , len);
    // Version is ignored
    unsigned char version = bytes->Dequeue();
    
    if (version != 0x03) {
        printf("ASWBXML only supports wbxml version 1.3.\n");
        return false;
    }
    // Public Identifier is ignored
    /*int publicIdentifier = */bytes->DequeueMultibyteInt();
    
    // Character set
    // Currently only UTF-8 is supported, throw if something else
    int charset = bytes->DequeueMultibyteInt();
    if (charset != 0x6A){
        printf("ASWBXML only supports UTF-8 encoded XML.\n");
        return false;
    }
    
    // String table length
    // This should be 0, MS-ASWBXML does not use string tables
    int stringTableLength = bytes->DequeueMultibyteInt();
    if (stringTableLength != 0){
        printf("WBXML data contains a string table.\n");
        return false;
    }
    // Now we should be at the body of the data.
    // Add the declaration
    TiXmlDeclaration * dec = new TiXmlDeclaration("1.0" ,"utf-8","");
    xmlDoc->LinkEndChild(dec);//link 进去的不能delete
    
    TiXmlElement* rootElement =  xmlDoc->RootElement();
    TiXmlElement* currentElement = rootElement;
    
    while (!bytes->Empty()){
        unsigned char currentByte = bytes->Dequeue();
        switch ((GlobalTokens)currentByte){
            case SWITCH_PAGE:
            {
                int newCodePage = (int)bytes->Dequeue();
                if (newCodePage >= 0 && newCodePage < 25){
                    currentCodePage = newCodePage;
                }else{
                    printf("Unknown code page ID 0x%x encountered in WBXML\n" , currentByte);
                    return false;
                }
                break;
            }
            case END:
            {
                if (currentElement->Parent() != NULL) {
                    currentElement = (TiXmlElement*)currentElement->Parent();
                }else{
                    printf("END global token encountered out of sequence\n");
                }
                break;
            }
            case OPAQUE:
            {
                int CDATALength = bytes->DequeueMultibyteInt();
                std::string text = bytes->DequeueString(CDATALength);
                TiXmlText * cDataText = new TiXmlText(text.c_str());
                cDataText->SetCDATA(true);
                currentElement->LinkEndChild(cDataText);//CDATA
                break;
            }
            case STR_I:
            {
                std::string str = bytes->DequeueString();
                currentElement->LinkEndChild(new TiXmlText(str.c_str()));
                break;
            }
                // According to MS-ASWBXML, these features aren't used
            case ENTITY:
            case EXT_0:
            case EXT_1:
            case EXT_2:
            case EXT_I_0:
            case EXT_I_1:
            case EXT_I_2:
            case EXT_T_0:
            case EXT_T_1:
            case EXT_T_2:
            case LITERAL:
            case LITERAL_A:
            case LITERAL_AC:
            case LITERAL_C:
            case PI:
            case STR_T:
            {
                printf("Encountered unknown global token 0x%x\n" , currentByte);
                return false;
            }
                // If it's not a global token, it should be a tag
            default:
            {
                bool hasAttributes = false;
                bool hasContent = false;
                
                hasAttributes = (currentByte & 0x80) > 0;
                hasContent = (currentByte & 0x40) > 0;
                
                unsigned char token = (unsigned char)(currentByte & 0x3F);
                
                if (hasAttributes){
                    // Maybe use Trace.Assert here?
                    printf("Token 0x%x has attributes.\n", token);
                    return false;
                }
                std::string strTag = codePages[currentCodePage]->GetTag(token);
                if (strTag.empty()){
                    char buff[100];
                    memset(buff, 1, sizeof(buff));
                    snprintf(buff, sizeof(buff), "UNKNOWN_TAG_%c" ,token);
                }
                //strTag = codePages[currentCodePage]->strXmlns + ':' + strTag;//prefix
                
                TiXmlElement * node = new TiXmlElement(strTag.c_str());
                if (node != NULL) {
                    std::string attrName = "xmlns";//"xmlns:" + codePages[currentCodePage]->strXmlns;
                    std::string attrValue = codePages[currentCodePage]->strNamespace;
                    node->SetAttribute(attrName.c_str(), attrValue.c_str());
                    if (currentElement != NULL) {
                        currentElement->LinkEndChild(node);
                    }else{
                        xmlDoc->LinkEndChild(node);
                    }
                }
                if (hasContent){
                    currentElement = node;
                }
                break;
            }
                
        }
    }
    delete bytes;
    return true;
}
void CASWBXML::GetBytes(unsigned char ** bytes , unsigned int* len)
{
    
    TiXmlElement* rootElement =  xmlDoc->RootElement();
    
    std::vector<unsigned char> byteList;
    byteList.push_back(versionByte);
    byteList.push_back(publicIdentifierByte);
    byteList.push_back(characterSetByte);
    byteList.push_back(stringTableLengthByte);
    
    EncodeNode(rootElement,byteList);
    
    *len = (int)byteList.size();
    *bytes = new unsigned char[*len];
    memset(*bytes, 0, *len);
    
    for (int i = 0 ; i < byteList.size(); ++i) {
        (*bytes)[i] = byteList[i];
    }
    
}
void CASWBXML::EncodeNode(TiXmlElement * node , std::vector<unsigned char> & byteList)
{
    switch (node->Type()){
        case TiXmlNode::TINYXML_ELEMENT:
        {
            ParseXmlnsAttributes(node);
            
            std::string tagName = node->Value();//tag name
            std::vector<std::string> array;
            ASUtils::Split(tagName, ':', array);
            
            std::string prefix, localName;
            if (array.size() > 1) {
                prefix = array[0];
                localName = array[1];
            }else {
                localName = array[0];
            }
            
            if (SetCodePageByXmlns(prefix))
            {
                byteList.push_back((unsigned char)SWITCH_PAGE);
                byteList.push_back((unsigned char)currentCodePage);
            }
            unsigned char token = codePages[currentCodePage]->GetToken(localName);
            if (node->FirstChild() != NULL){
                token |= 0x40;
            }
            byteList.push_back(token);
            if (node->FirstChild() != NULL){
                TiXmlNode* pElement = node->FirstChild();
                for (;pElement ; pElement = pElement->NextSibling()) {
                    EncodeNode((TiXmlElement*)pElement, byteList);
                }
                byteList.push_back((unsigned char)END);
            }
            break;
        }
        case TiXmlNode::TINYXML_TEXT:
        {
            if (((TiXmlText *)node)->CDATA()) {
                byteList.push_back((unsigned char)OPAQUE);
                std::string text = node->Value();
                this->EncodeOpaque(text, byteList);
            }else{
                byteList.push_back((unsigned char)STR_I);
                std::string text = node->Value();
                this->EncodeString(text, byteList);
            }
            break;
        }
        default:
            break;
    }
}
int CASWBXML::GetCodePageByXmlns(std::string& xmlns)
{
    for (int i = 0; i < codePages.size(); i++)
    {
        if (ASUtils::UppercaseString(codePages[i]->strXmlns) == ASUtils::UppercaseString(xmlns)){
            return i;
        }
    }
    return -1;
}
int CASWBXML::GetCodePageByNamespace(std::string& nameSpace)
{
    for (int i = 0; i < codePages.size(); i++)
    {
        if (ASUtils::UppercaseString(codePages[i]->strNamespace) == ASUtils::UppercaseString(nameSpace)){
            return i;
        }
    }
    
    return -1;
}
bool CASWBXML::SetCodePageByXmlns(std::string& xmlns)
{
    if (xmlns.empty())
    {
        // Try default namespace
        if (currentCodePage != defaultCodePage){
            currentCodePage = defaultCodePage;
            return true;
        }
        return false;
    }
    // Try current first
    if (ASUtils::UppercaseString(codePages[currentCodePage]->strXmlns) == ASUtils::UppercaseString(xmlns)){
        return false;
    }
    for (int i = 0; i < codePages.size(); i++)
    {
        if (ASUtils::UppercaseString(codePages[i]->strXmlns) == ASUtils::UppercaseString(xmlns)){
            currentCodePage = i;
            return true;
        }
    }
    printf("Unknown Xmlns: %s\n.", xmlns.c_str());
    return false;
}
void CASWBXML::ParseXmlnsAttributes(TiXmlElement * node)
{
    TiXmlAttribute* attr =  node->FirstAttribute();
    for (; attr; attr = attr->Next()) {
        std::string nameSpace = attr->Value();
        int codePage = GetCodePageByNamespace(nameSpace);
        
        std::vector<std::string> array;
        ASUtils::Split(attr->Name(), ':', array);
        std::string prefix, localName;
        if (array.size() > 1) {
            prefix = array[0];
            localName = array[1];
        }else {
            localName = array[0];
        }
        if (ASUtils::UppercaseString(localName) == "XMLNS"){
            defaultCodePage = codePage;
        }else if (ASUtils::UppercaseString(prefix) == "XMLNS"){
            codePages[codePage]->strXmlns = localName;
        }
    }
}
void CASWBXML::EncodeString(std::string& value , std::vector<unsigned char> & byteList)
{
    for (int i = 0; i < value.size(); i++){
        byteList.push_back((unsigned char)value[i]);
    }
    byteList.push_back(0x00);
}
void CASWBXML::EncodeOpaque(std::string& value , std::vector<unsigned char> & byteList)
{
    EncodeMultiByteInteger((int)value.size() , byteList);
    for (int i = 0; i < value.size(); i++){
        byteList.push_back((unsigned char)value[i]);
    }
}
void CASWBXML::EncodeMultiByteInteger(int value , std::vector<unsigned char> & byteList)
{
    std::vector<unsigned char> bytes;
    while (value > 0)
    {
        unsigned char addByte = (unsigned char)(value & 0x7F);
        
        if (bytes.size() > 0)
        {
            addByte |= 0x80;
        }
        bytes.insert(bytes.begin(), addByte);
        value >>= 7;
    }
    for (std::vector<unsigned char>::const_iterator it=bytes.begin(); it != bytes.end(); ++it) {
        byteList.push_back(*it);
    }
}





