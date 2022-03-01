#include "GmailHeaderType.h"

GmailHeaderType::GmailHeaderType()
{
	 DeliveredTo = "none";
	 ReceivedBy = "none";
	 XGoogle = "none";
	 Received = "none";
	 ContentType1 = "none";
	 ReplyTo = "none";
	 MessageID = "none";
	 Subject = "none";
	 MIMEVer = "none";
	 ContentType2 = "none";
	 ContentType3 = "none";
	 ContentTransfer = "none";
	 date = "none";
	 to = "none";
	 from = "none";
}
GmailHeaderType::GmailHeaderType(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8, string s9, string s10, string s11, string s12, string s13, string s14, string s15)
{
	 DeliveredTo = s1;
	 ReceivedBy = s2;
	 XGoogle = s3;
	 Received = s4;
	 ContentType1 = s5;
	 ReplyTo = s6;
	 MessageID = s7;
	 Subject = s8;
	 MIMEVer = s9;
	 ContentType2 = s10;
	 ContentType3 = s11;
	 ContentTransfer = s12;
	 date = s13;
	 from = s14;
	 to = s15;

}
GmailHeaderType::~GmailHeaderType()
{
	//destructor
}

