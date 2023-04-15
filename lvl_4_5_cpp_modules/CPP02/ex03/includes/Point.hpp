#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &to_copy);
		Point& operator=(const Point &original);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;
	private:
		Fixed const x;
		Fixed const y;
};

#endif // POINT_HPP