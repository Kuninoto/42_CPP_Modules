#include "Point.hpp"

static Fixed abs(Fixed x)
{
	if (x < 0)
		return x * -1;
	return x;
}

/* Formula
	( x1*(y2 - y3) 
	+ x2*(y3 - y1) 
	+ x3*(y1 - y2) ) / 2
*/	

static Fixed triangle_area(Point const p1, Point const p2, Point const p3)
{
	return (abs(
		  		(p1.getX() * (p2.getY() - p3.getY())
		  		+ p2.getX() * (p3.getY() - p1.getY())
		  		+ p3.getX() * (p1.getY() - p2.getY())
		  		) / 2)
		   );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = triangle_area(a, b, c);
    Fixed pbcArea = triangle_area(point, b, c);
    Fixed pacArea = triangle_area(point, c, a);
    Fixed pabArea = triangle_area(point, a, b);

	return (abcArea == (pbcArea + pacArea + pabArea));
}
