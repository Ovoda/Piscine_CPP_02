#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point( void );
		Point( Point const & src );
		Point( float const x, float const y );
		~Point();

		Point &		operator=( Point const & rhs );

		//getters and setters
		Fixed const	getX() const;
		Fixed const	getY() const;

	private:
		Fixed const _x;
		Fixed const _y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */