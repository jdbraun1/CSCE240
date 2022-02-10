//Rectangle Header


#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape
{
	double area;
	double perimeter;
	string ErrorMessage;


public:
	Rectangle();
	Rectangle(string, double, double, string);

	virtual ~Rectangle();
	void setArea(double);
	void setPerimeter(double);
	double getArea();
	double getPerimeter();
	string getErrorMessage();


};

#endif
