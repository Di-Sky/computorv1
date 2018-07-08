/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNParser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 18:01:56 by omartyno          #+#    #+#             */
/*   Updated: 2018/07/03 18:08:40 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPNPARSER_HPP
# define RPNPARSER_HPP

# define OPERATOR 1
# define NUMBER 2
# define VARIABLE 4

typedef union	u_parser_data
{
	int			num;
	char		var;
	char		op;
}

typedef struct	s_exp_data
{

}				t_exp_data;

class RPNParser
{

private:
	std::stack<char>	operations;
	std::list<>
}

#endif
