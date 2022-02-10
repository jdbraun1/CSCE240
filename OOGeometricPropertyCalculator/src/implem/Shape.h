//Shape Header

#ifndef Shape_H_
#define Shape_H_

#include <string>

using namespace std;

class Shape {
protected:
	string myshape;

public:
	Shape();
	Shape(string);
	virtual ~Shape();

	string getShape();
	void setShape(string);
};

#endif
