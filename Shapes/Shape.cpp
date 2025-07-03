#include "Shape.h"

std::ostream& operator<<(std::ostream& stream, Shape& shape) {
	shape.Print(stream);
	return stream;
}
