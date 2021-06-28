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
    bool ret;
    Point a(0, 0);
    Point b(200, 0);
    Point c(0, 20);
    Point point(6, 6);


    std::cout << Fixed(2) + Fixed(2) << std::endl;

    ret = bsp(a, b, c, point);
    print_message(a, b, c, point, ret);

    return 0;
}