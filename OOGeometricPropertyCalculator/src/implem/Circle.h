//Circle Header


#ifndef Circle_H_
#define Circle_H_

#include "Shape.h"

class Circle: public Shape
{
	double area;
	double perimeter;
	string ErrorMessage;


public:
	Circle();
	Circle(string, double, double, string);

	virtual ~Circle();
	void setArea(double);
	void setPerimeter(double);
	double getArea();
	double getPerimeter();
	string getErrorMessage();


};

#endif
