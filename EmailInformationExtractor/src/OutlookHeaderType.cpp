#include "OutlookHeaderType.h"

OutlookHeaderType::OutlookHeaderType()
{
	 RecievedFrom = "none";
	 Authentication = "none";
	RecievedFrom2 = "none";
	ContentType = "none";
	ContentTransfer = "none";
	CC = "none";
	Subject = "none";
	ThreadTopic = "none";
	ThreadIndex = "none";
	MessageID = "none";
	References = "none";
	InReply = "none";
	AcceptLanguage = "none";
	ContentLanguage = "none";
	XMSAttach = "none";
	XMSExchange = "none";
}
OutlookHeaderType::OutlookHeaderType(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8, string s9, string s10, string s11, string s12, string s13, string s14, string s15, string s16, string s17, string s18, string s19)
{
	RecievedFrom = s1;
		 Authentication = s2;
		RecievedFrom2 = s3;
		ContentType = s4;
		ContentTransfer = s5;
		CC = s6;
		Subject = s7;
		ThreadTopic = s8;
		ThreadIndex = s9;
		MessageID = s10;
		References = s11;
		InReply = s12;
		AcceptLanguage = s13;
		ContentLanguage = s14;
		XMSAttach = s15;
		XMSExchange = s16;
		date = s17;
		from = s18;
		to = s19;
}
OutlookHeaderType::~OutlookHeaderType(){
	//destructor
}
