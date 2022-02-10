#include "Rectangle.h"

Rectangle::Rectangle()
{
	myshape = "Rectangle";
	area = 0;
	perimeter = 0;
	ErrorMessage = "Unable to calculate";
}

Rectangle::Rectangle(string n, double a, double p, string error)
{
	// assign shape
	myshape = n;
	area = a;
	perimeter = p;
	ErrorMessage = error;

}
Rectangle::~Rectangle()
{
	// TODO Auto-generated destructor stub
}
double Rectangle::getArea() {
	return area;
}
double Rectangle::getPerimeter() {
	return perimeter;
}
string Rectangle::getErrorMessage(){
	return ErrorMessage;
}
void Rectangle::setArea(double a)
{
	area = a;
}
void Rectangle::setPerimeter(double p)
{
	perimeter = p;
}
