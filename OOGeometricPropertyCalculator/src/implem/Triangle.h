//Triangle Header


#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape
{
	double area;
	double perimeter;
	string ErrorMessage;


public:
	Triangle();
	Triangle(string, double, double, string);

	virtual ~Triangle();
	void setArea(double);
	void setPerimeter(double);
	double getArea();
	double getPerimeter();
	string getErrorMessage();


};

#endif
