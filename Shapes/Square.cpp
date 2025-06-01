#include "Square.h"

Square::Square()
{
}

Square::Square(Point topLeft, Point botRight)
{
	this->topLeft = topLeft;
	this->botRight = botRight;
}

Square::Square(Point topLeft, double sideLength) : Rectangle(topLeft, sideLength, sideLength)
{
}
