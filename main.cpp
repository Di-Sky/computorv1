/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:07:00 by omartyno          #+#    #+#             */
/*   Updated: 2018/07/04 19:18:55 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale> //isalpha

t_var		readvar( char &(*start), char &(*end) ) {
	t_var	v;
	long	n;

	errno = 0;
	n = strtol(start, &end, 10);
	if (errno)
		;//exc
	if (start == end) {
		while ( std::isalpha(*end) )
			end++;
		if ( start == end )
			;//exc
		v.num = 1;
		v.type = std::string(start, end);
		start = end;
		return v;
	}
	v.num = n;
	start = end;
	return v;
}

std::string	readop( char &(*start), char &(*end) ) {
	std::string		operations[] = {
		"+", "-", "*", "^"
	}

	for ( short i = 0; i < operations.length(); i++ )
	{
		short	j = 0;
		while ( operations[i][j] == start[j] && operations[i][j] )
			j++;
	}
}

Polynomial	*parseString(std::string &input) {
	input.erase(input.remove_if(input.begin(), input.end(), std::isspace), input.end());

	char			*cstr = new char [input.length() + 1];
	char			*start = cstr;
	char			*end;
	int				side = 1;

	std::strcpy(cstr, input.c_str());

	while (*start)
	{
		t_var	var = { .num = 0; .char = ' '; .degree = 0; }
		if ( readnum( start, end, var.num ) ) {
			readX( start, end, var, true );
		}
		else {
			if ( readX( start, end, var, false ) ) {
				continue;
			}
			check_end( start, end, var, side );
		}
	}
}

int 		main( int argc, char **argv ) {
	if ( argc != 2 ) {
		std::cout << "Please, input the polynomial equation to solve" << std::endl;
		return 1;
	}

	std::string		equation = argv[1];

}