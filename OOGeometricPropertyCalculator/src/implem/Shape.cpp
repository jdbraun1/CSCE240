

#include "Shape.h"

Shape::Shape()
{
	myshape = "None";

}

Shape::Shape(string n)
{
	// assign shape
	myshape = n;

}

Shape::~Shape()
{
	// TODO Auto-generated destructor stub
}

string Shape::getShape() {
	return myshape;
}


void Shape::setShape(string n) {
	myshape = n;

}
