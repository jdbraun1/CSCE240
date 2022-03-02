#ifndef District_H_
#define District_H_

#include <string>

using namespace std;

class District{
protected:
	int districtNum;
	string Rep;


public:
	District();
	District(int, string);
	virtual ~District();

	int getDistrictNum();
	string getDistrictRep();
	void setDistrictNum(int);
	void setDistrictRep(string);
};
#endif
