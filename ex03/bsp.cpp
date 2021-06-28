#include "Point.hpp"

Fixed ft_abs(Fixed num)
{
	if (num < 0)
		return (num * Fixed(-1));
	return (num);
}

Fixed	dist( Point const & a, Point const & b ) {


	return Fixed((a.getX() - b.getX()) + (a.getY() - b.getY()));
}

bool	is_on_line(Point const & a, Point const & b, Point const & point) {
	if (dist(a, point) + dist(b, point) == dist(a, b))
		return (true);
	return (false);
}

Fixed getArea(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = Fixed(0.5f)
		* (a.getX() * (b.getY() - c.getY())
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY())));
		
	return (ft_abs(area));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A, A1, A2, A3;

	A = getArea(a, b, c);
	A1 = getArea(a, b, point);
	A2 = getArea(a, point, c);
	A3 = getArea(point, b, c);

	if (A == (A1 + A2 + A3)
		&& (A1 != 0)
		&& (A2 != 0)
		&& (A3 != 0))
		return (true);
	return (false);
}