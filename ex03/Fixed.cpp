#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fp_value(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(int const value) {
	_fp_value = value << _nb_frac_bit;
}

Fixed::Fixed(float const value) {
	_fp_value = (int)roundf(value * 256);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		_fp_value = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator++( void ) {
	_fp_value++;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--( void ) {
	_fp_value--;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed	Fixed::operator+(Fixed const & rhs ) const {
	float new_value = (float)((float)this->getRawBits() + (float)rhs.getRawBits());
	new_value /= 256;
	return Fixed(new_value);
}

Fixed	Fixed::operator-(Fixed const & rhs ) const {
	float new_value = (float)((float)this->getRawBits() - (float)rhs.getRawBits());
	new_value /= 256;
	return Fixed(new_value);
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {
	float i = 1 << (_nb_frac_bit * 2);
	float new_value = (float)(this->getRawBits() * rhs.getRawBits());
	new_value /= i;
	return Fixed(new_value);
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {
	float new_value = (float)(this->getRawBits()) / (float)rhs.getRawBits();
	return Fixed(new_value);
}

bool Fixed::operator<(Fixed const & rhs) const {
	return (_fp_value < rhs.getRawBits());
}

bool Fixed::operator>(Fixed const & rhs) const {
	return (_fp_value > rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const {
	return (_fp_value >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const {
	return (_fp_value <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const {
	return (_fp_value == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const {
	return (_fp_value != rhs.getRawBits());
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat( void ) const {
	return (float(_fp_value) / 256);
}

int	Fixed::toInt( void ) const {
	return (_fp_value >> _nb_frac_bit);
}

Fixed	&Fixed::max( Fixed & a, Fixed & b ) {
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const & a, Fixed const & b ) {
	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::min( Fixed & a, Fixed & b ) {
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min( Fixed const & a, Fixed const & b ) {
	if (a < b)
		return (a);
	return (b);
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