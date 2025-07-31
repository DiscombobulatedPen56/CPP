#include "Rectangle.h"

Rectangle::Rectangle() : topLeft(0, 1), botRight(1, 0)
{
}

Rectangle::Rectangle(Point topLeft, Point botRight) : topLeft(topLeft), botRight(botRight)
{
}

Rectangle::Rectangle(Point topLeft, double width, double height) : topLeft(topLeft)
{
	this->botRight.x = topLeft.x + width;
	this->botRight.y = botRight.y - height;
}

double Rectangle::Width()
{
	return this->botRight.x - this->topLeft.x;
}

double Rectangle::Height()
{
	return this->topLeft.y - this->botRight.y;
}

void Rectangle::Print(std::ostream& stream)
{
	stream << "Rectangle:" << topLeft << " " << botRight << "\n";
}

double Rectangle::Area() {
	return Width() * Height();
}

double Rectangle::Perimeter() {
	return 2 * (Width() + Height());
}
