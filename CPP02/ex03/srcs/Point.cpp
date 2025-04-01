#include "Point.hpp"

Point::Point(void) : x(0), y(0) {};

Point::Point(const float x, const float y) : x(x), y(y) {};

Point::Point(const Point &to_copy) {
	*this = to_copy;
};

Point& Point::operator=(const Point &original)
{
	(Fixed)this->x = original.getX();
	(Fixed)this->y = original.getY();
	return *this;
}

Point::~Point(void) {};

Fixed Point::getX(void) const {
	return this->x;
}

Fixed Point::getY(void) const {
	return this->y;
}
