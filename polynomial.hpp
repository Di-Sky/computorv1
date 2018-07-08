/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:11:38 by omartyno          #+#    #+#             */
/*   Updated: 2018/07/04 19:15:03 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

typedef struct 	s_var
{
	long		degree;
	long		num;
	std::string	type;
}				t_var;

class Polynomial
{
public:
	Polynomial( std::string &input );
	Polynomial( const Polynomial &src );
	~Polynomial( void );

	Polynomial &	operator=( const Polynomial &src );



private:
	std::vector<int>	operands;

}

#endif
