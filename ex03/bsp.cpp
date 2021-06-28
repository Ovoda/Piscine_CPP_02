#include "Point.hpp"

Fixed   getArea(Point const a, Point const b, Point const c) {
    Fixed area;

    area = Fixed(0.5f) * ((b.getY() * c.getX() * Fixed(-1)) 
            + (a.getY() * (b.getX() + c.getX() * Fixed(-1)))
            + (a.getX() * (b.getY() - c.getY()))
            + (b.getX() * c.getY()));
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area, t, s;

    area = getArea(a, b, c);

    std::cout << area<< std::endl;

    s = Fixed(1)/(Fixed(2) * area)
        * ((a.getY() * c.getX()) - (a.getX() - c.getY()) + ((c.getY() - a.getY()) * point.getX())
        + (a.getX() - c.getX()) * point.getY());

    std::cout << "s : " << s << std::endl;

    t = Fixed(1)/(Fixed(2) * area)
        * ((a.getX() * b.getY()) - (a.getY() * b.getX()) + ((a.getY() - b.getY()) * point.getX())
        + (b.getX() - a.getX()) * point.getY());

    std::cout << "t : " << t << std::endl;

    if (s > Fixed(0) && 
        t > Fixed(0) &&
        Fixed(1) - s - t > Fixed(0))
        return (true);
    return (false);
}