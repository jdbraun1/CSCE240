//Base Email Header Class

#ifndef BaseEmailHeaderType_H_
#define BaseEmailHeaderType_H_

#include <string>

using namespace std;

class BaseEmailHeaderType{
protected:
	string date;
	string from;
	string to;


public:
	BaseEmailHeaderType();
	BaseEmailHeaderType(string, string, string);
	virtual ~BaseEmailHeaderType();

	string getDate();
	string getFrom();
	string getTo();
	void setDate(string);
	void setFrom(string);
	void setTo(string);
};

#endif
