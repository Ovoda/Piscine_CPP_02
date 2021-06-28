#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	_fp_value = value << _nb_frac_bit;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	_fp_value = (int)roundf(value * 256);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		_fp_value = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << float(rhs.getRawBits()) / 256;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat( void ) const {
	return (float(_fp_value >> 8));
}

int	Fixed::toInt( void ) const {
	return (_fp_value >> 8);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits(void) const {
	return (_fp_value);
}

void	Fixed::setRawBits( int const raw ) {
	_fp_value = raw;
}

/* ************************************************************************** */