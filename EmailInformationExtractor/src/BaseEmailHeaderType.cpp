
#include "BaseEmailHeaderType.h"

BaseEmailHeaderType::BaseEmailHeaderType()
{
	date = "None";
	to = "None";
	from = "None";

}

BaseEmailHeaderType::BaseEmailHeaderType(string n, string f, string t)
{
	// assign content
	date = n;
	from = f;
	to = t;
}

BaseEmailHeaderType::~BaseEmailHeaderType()
{
	// TODO Auto-generated destructor stub
}

string BaseEmailHeaderType::getDate() {
	return date;
}

string BaseEmailHeaderType::getFrom()
{
	return from;
}
string BaseEmailHeaderType::getTo()
{
	return to;
}

void BaseEmailHeaderType::setDate(string n) {
	date = n;

}
void BaseEmailHeaderType::setFrom(string n) {
	from = n;

}
void BaseEmailHeaderType::setTo(string n) {
	to = n;

}
