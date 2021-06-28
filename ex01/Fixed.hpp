#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed();
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed &		operator=( Fixed const & rhs );

	private:
		int					_fp_value;
		static const int	_nb_frac_bit = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif /* *********************************************************** FIXED_H */