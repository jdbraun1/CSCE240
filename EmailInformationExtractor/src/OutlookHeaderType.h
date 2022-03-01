//Outlook Header type header

#ifndef OutlookHeaderType_H_
#define OutlookHeaderType_H_

#include "BaseEmailHeaderType.h"

class OutlookHeaderType: public BaseEmailHeaderType
{
	string RecievedFrom;
	string Authentication;
	string RecievedFrom2;
	string ContentType;
	string ContentTransfer;
	string CC;
	string Subject;
	string ThreadTopic;
	string ThreadIndex;
	string MessageID;
	string References;
	string InReply;
	string AcceptLanguage;
	string ContentLanguage;
	string XMSAttach;
	string XMSExchange;


public:
	OutlookHeaderType();
	OutlookHeaderType(string,string,string,string, string, string, string, string, string, string, string, string, string, string,string,string,string,string,string);
	virtual ~OutlookHeaderType();
};

#endif
