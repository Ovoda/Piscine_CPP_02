#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void    print_message( Point const a, Point const b, Point const c, Point const point, bool ret) {

    std::cout
        << "A: " << a << std::endl
        << "B: " << b << std::endl
        << "C: " << c << std::endl
        << std::endl;
    if (ret)
        std::cout << "The point " << point << " is inside the triangle" << std::endl;
    else
        std::cout << "The point " << point << " is NOT inside the triangle" << std::endl;

}

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point point(3, 3);

    print_message(a, b, c, point, bsp(a, b, c, point));

    return 0;
}