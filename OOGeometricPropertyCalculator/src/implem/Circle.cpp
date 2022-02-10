#include "Circle.h"

Circle::Circle()
{
	myshape = "Circle";
	area = 0;
	perimeter = 0;
	ErrorMessage = "Unable to calculate";
}

Circle::Circle(string n, double a, double p, string error)
{
	// assign shape
	myshape = n;
	area = a;
	perimeter = p;
	ErrorMessage = error;

}
Circle::~Circle()
{
	// TODO Auto-generated destructor stub
}
double Circle::getArea() {
	return area;
}
double Circle::getPerimeter() {
	return perimeter;
}
string Circle::getErrorMessage(){
	return ErrorMessage;
}
void Circle::setArea(double a)
{
	area = a;
}
void Circle::setPerimeter(double p)
{
	perimeter = p;
}

