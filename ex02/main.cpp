#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    std::cout << "______Subject tests______" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "______Additional tests______" << std::endl;
    Fixed x(21);
    Fixed y(21.21f);
    Fixed z(21.20f);

    std::cout << x + x << " => 21 + 21" << std::endl;
    std::cout << x - x << " => 21 - 21" << std::endl;
    std::cout << x * x << " => 21 * 21" << std::endl;
    std::cout << x / x << " => 21 / 21" << std::endl;
    std::cout << y + y << " => 21.21 + 21.21" << std::endl;
    std::cout << y - z << " => 21.21 - 21.20" << std::endl;
    std::cout << y * y << " => 21.21 * 21.21" << std::endl;
    std::cout << y / Fixed(1.2f) << " => 21.21 / 1.2" << std::endl;
    std::cout << Fixed(23.5f) - Fixed(1.2f) << " => 23.5 - 1.2" << std::endl;
    std::cout << Fixed(23.5f) + Fixed(1.2f) << " => 23.5 + 1.2" << std::endl;

    if (x < y)
        std::cout << "x < y" << std::endl;
    if (x <= y)
        std::cout << "x <= y" << std::endl;
    if (x > y)
        std::cout << "x > y" << std::endl;
    if (x >= y)
        std::cout << "x >= y" << std::endl;
    if (x == y)
        std::cout << "x == y" << std::endl;
    if (x != y)
        std::cout << "x != y" << std::endl;

    std::cout << Fixed::max(x, y) << " => max (21, 21.2109)"<< std::endl;
    std::cout << Fixed::min(x, y) << " => min (21, 21.2109)"<< std::endl;

    return 0;
}