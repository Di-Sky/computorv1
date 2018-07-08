/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:11:30 by omartyno          #+#    #+#             */
/*   Updated: 2018/07/04 18:50:54 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

Polynomial::Polynomial( void );

bool		Polynomial::readnum(char **start, char **end, int *num) {
	errno = 0;
	*num = strtol(*start, end, 10);
	if ( start == end || errno )
		return false;
	return true;
}

bool		Polynomial::readnum( char &(*s), char &(*e), int &n ) {
	errno = 0;
	n = strtol(start, &end, 10);
	if (start == end || errno)
		return false;
	return true;
}

bool		readX( char &(*s), char &(*e), int &n ) {
	char	mult[] = "*X^";

	int i = 0;
	for (; mult[i] && mult[i] == start[i]; i++) ;
	if (!mult[i]) {
		end = start + i;
		start = end;
		if ( !readnum( start, end, var.num ) )
			;//exc
		start = end;
		return true;
	}
	switch (i) {
		case 0:
			return false;
			break;
		case 1:
			;//exc
			break;
		case 2:
			
	}
	if ( i == 0 ) {
		return false;
	}
	if ( i == 1 ) {
		;//exc X
	}
	if 
}

void		Polynomial::parseString( std::string &input ) {
	//remove whitespace
	input.erase(input.remove_if(input.begin(), input.end(), std::isspace), input.end());

	// char	mult[] = "*X^";
	char	*cstr = new char [this->_data.length() + 1];
	char	*start = cstr;
	char	*end;
	int		side = 1;

	std::strcpy(cstr, this->_data.c_str());

	while ( *start ) {
		t_var var = { .num = 0; .char = ' '; .degree = 0; }
		if ( readnum( start, end, var.num ) ) {
			start = end;
			readX( start, end, var );
			// push(var);
		}
		else {
			if ( readX(start, end, var) ) {
				continue;
			}
			check_end(start, end, var, side);
		}
	}
}










	while (*start)
	{
		errno = 0;
		int		num = strtol(start, &end, 10);
		if (start == end) {
			if ( start[0] == '=' && side == 1)
			{
				side = -1;
				start++;
				end++;
			}
			else {
				delete [] cstr;
				//exception
			}
		}
		else {
			int i = 0;
			int degree = -1;
			for (; mult[i]; i++)
				if ( mult[i] != end[i] ) {
					if ( i == 0 )
						degree = 0;
					else if ( i == 2 )
						degree = 1;
					else {
						delete [] cstr;
						//exception
					}
				}
			start = end + i;
			end = start;
			int degree = strtol(startm &end, 10);
			if ( start == end ) {
				delete [] cstr;
				//exception
			}
			if ( degree < 0 ) {
				delete [] cstr;
				//exception
			}
			if ( this->operands.size() < degree )
				this->operands.resize( degree );
			this->operands[degree] += num * side;
		}
	}
}
