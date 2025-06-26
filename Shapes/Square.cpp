#include "Square.h"

Square::Square()
{
}

Square::Square(Point topLeft, Point botRight)
{
	this->topLeft = topLeft;
	this->botRight = botRight;
}

void Square::Print(std::ostream& stream)
{
	stream << "Square: " << topLeft << " " << botRight;
}

Square::Square(Point topLeft, double sideLength) : Rectangle(topLeft, sideLength, sideLength)
{
}


