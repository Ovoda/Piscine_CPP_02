#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0) {}

Point::Point( const Point & src ) : _x(src.getX()), _y(src.getY()) {
}

Point::Point( float const x, float const y ) : _x(x), _y(y) {

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	( void ) rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << ", y = " << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed const	Point::getX(void) const {
	return (_x);
}

Fixed const	Point::getY(void) const {
	return (_y);
}

/* ************************************************************************** */