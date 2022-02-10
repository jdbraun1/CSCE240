#include "Triangle.h"

Triangle::Triangle()
{
	myshape = "Triangle";
	area = 0;
	perimeter = 0;
	ErrorMessage = "Unable to calculate";

}

Triangle::Triangle(string n, double a, double p, string error)
{
	// assign shape
	myshape = n;
	area = a;
	perimeter = p;
	ErrorMessage = error;

}
Triangle::~Triangle()
{
	// TODO Auto-generated destructor stub
}

double Triangle::getArea() {
	return area;
}
double Triangle::getPerimeter() {
	return perimeter;
}
string Triangle::getErrorMessage(){
	return ErrorMessage;
}
void Triangle::setArea(double a)
{
	area = a;
}
void Triangle::setPerimeter(double p)
{
	perimeter = p;
}
