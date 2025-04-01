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

static Fixed triangleArea(Point const p1, Point const p2, Point const p3)
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
	Fixed abcArea = triangleArea(a, b, c);
    Fixed pbcArea = triangleArea(point, b, c);
    Fixed pacArea = triangleArea(point, c, a);
    Fixed pabArea = triangleArea(point, a, b);

	return (abcArea == (pbcArea + pacArea + pabArea));
}
