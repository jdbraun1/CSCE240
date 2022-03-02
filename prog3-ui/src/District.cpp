#include "District.h"

District::District()
{
	districtNum = 0;
	Rep = "None";

}
District::District(int n, string f)
{
	// assign content
	districtNum = n;
	Rep = f;
}

District::~District()
{
	// TODO Auto-generated destructor stub
}
int District::getDistrictNum()
{
	return districtNum;
}
string District::getDistrictRep()
{
	return Rep;
}

void District::setDistrictNum(int n) {
	districtNum = n;

}
void District::setDistrictRep(string n) {
	Rep = n;

}
