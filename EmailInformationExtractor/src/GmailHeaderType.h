//Gmail Header Type header

#ifndef GmailHeaderType_H_
#define GmailHeaderType_H_

#include "BaseEmailHeaderType.h"

class GmailHeaderType: public BaseEmailHeaderType
{
	string DeliveredTo;
	string ReceivedBy;
	string XGoogle;
	string Received;
	string ContentType1;
	string ReplyTo;
	string MessageID;
	string Subject;
	string MIMEVer;
	string ContentType2;
	string ContentType3;
	string ContentTransfer;




public:
	GmailHeaderType();
	GmailHeaderType(string, string, string, string, string, string, string, string, string, string,string,string,string,string, string);
	virtual ~GmailHeaderType();

	/*string getDeliverTo();
	string getReceivedBy();
	string getXGoogle();
	string Received();
	string getContentType();
	string getReplyTo();
	string getMessageID();
	string getSubject();
	string getMIMEVer();
	string getContentType();
	string getContentTransfer();*/

	/*void setDeliverTo(string);
	void setReceivedBy(string);
	void setXGoogle(string);
	void setReceived(string);
	void setContentType1(string);
	void setReplyTo(string);
	void setMessageID(string);
	void setSubject(string);
	void setMIMEVer(string);
	void setContentType2(string);
	void setContentType3(string);
	void setContentTransfer(string);*/

};
#endif
