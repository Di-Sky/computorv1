/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regextest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:47:05 by omartyno          #+#    #+#             */
/*   Updated: 2018/07/08 18:12:56 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <list>

typedef struct	s_equation
{
	std::list<std::string>				oper;
	std::list<std::string>				vars;
	std::list<std::string>::iterator	o_it;
	std::list<std::string>::iterator	v_it;
}				t_equation;

t_equation	showmatches(std::string &half) {
	std::string	fnum = "\\d+\\.\\d+";
	std::string	wnum = "\\d+";
	std::string	num = "(?:" + fnum + "|" + wnum + ")";
	std::string	skip = "\\s*";
	std::string	opr = "[\\+\\*\\^-]";

	std::stringstream	ss;

	ss
	<< "(?:" << skip << "(" << num << "?[A-Za-z]|" << num << ")" << skip
	<< "(" << opr << ")?" << skip << ")";

	std::regex	regpoly(ss.str());
	std::smatch	matches;
	// std::regex_match(half, matches, regpoly);

	t_equation	equ;
	// std::list<std::string>	oper;
	// std::list<std::string>	vars;
	std::smatch::iterator	it;
	while (std::regex_search(half, matches, regpoly)) {
		// std::cout << matches.size();
		it = matches.begin();
		equ.vars.push_back(*++it);
		equ.oper.push_back(*++it);
		// for (std::smatch::iterator it = matches.begin(); it != matches.end(); it++) {
			// if ( it == matches.begin() ) it++;
			// std::cout << *it << std::endl;
		// }
		// std::cout << std::endl;
		half = matches.suffix().str();
	}

	// equ.oper.reverse();
	// equ.vars.reverse();
	equ.o_it = equ.oper.begin();
	equ.v_it = equ.vars.begin();

	// while (equ.o_it != equ.oper.end() && equ.v_it != equ.vars.end()) {
	// 	std::cout << *(equ.v_it) << " " << *(equ.o_it) << std::endl;
	// 	if (equ.o_it != equ.oper.end()) 
	// 		equ.o_it++;
	// 	if (equ.v_it != equ.vars.end()) 
	// 		equ.v_it++;
	// }

	// while (!equ.oper.empty() && !equ.vars.empty()) {
	// 	std::cout << equ.vars.front() << " " << equ.oper.front() << " ";
	// 	equ.vars.pop();
	// 	equ.oper.pop();
	// }
	// std::cout << std::endl;
	return equ;
}


bool	validequation(std::string &pol) {
	std::string	fnum = "\\d+\\.\\d+";
	std::string	wnum = "\\d+";
	std::string	num = "(?:" + fnum + "|" + wnum + ")";
	std::string	skip = "\\s*";
	std::string	oper = "[\\+\\*\\^-]";

	std::stringstream	ss;

	ss
	<< "(" << skip << "(?:" << num << "?[A-Za-z]|" << num << ")" << skip << oper << skip << ")*"
	<< "(" << skip << "(?:" << num << "?[A-Za-z]|" << num << ")" << skip << ")="
	<< "(" << skip << "(?:" << num << "?[A-Za-z]|" << num << ")" << skip << oper << skip << ")*"
	<< "(" << skip << "(?:" << num << "?[A-Za-z]|" << num << ")" << skip << ")";

	// std::cout << std::endl << ss.str() << std::endl;
	// std::regex	regequation("(\\s*(?:\\d*[A-Za-z]|\\d+)\\s*[\\+\\*\\^\\/-]\\s*)*(\\s*(?:\\d*[A-Za-z]|\\d+)\\s*)=(\\s*(?:\\d*[A-Za-z]|\\d+)\\s*[\\+\\*\\^\\/-]\\s*)*(\\s*(?:\\d*[A-Za-z]|\\d+)\\s*)");
	std::regex	regequation(ss.str());
	return std::regex_match(pol, regequation);
}

t_equation	reducepoly(t_equation &left, t_equation &right) {
	t_equation	supermonster = left;

	supermonster.oper.pop_back();
	supermonster.oper.push_back("-");
	supermonster.vars.insert(supermonster.vars.end(), right.vars.begin(), right.vars.end());
	for (right.o_it = right.oper.begin(); right.o_it != right.oper.end(); right.o_it++) {
		std::string		op = *right.o_it;
		if (op == "+") op = "-";
		if (op == "-") op = "+";
		supermonster.oper.push_back(op);
	}
	return supermonster;
}

void	parsepoly(std::string &pol) {
	//Check equation
	if (!validequation(pol))
	{
		std::cout << "shieeeeeet" << std::endl;
		return;
	}

	//Split
	std::size_t	fpos = pol.find("=");
	std::cout << pol << std::endl;

	std::string	left(pol, 0, fpos);
	std::string	right(pol, fpos + 1, pol.length() - (fpos + 1));

	// std::cout << left << std::endl;
	// std::cout << right << std::endl;

	//End split

	// std::cout << "left matches: " << std::endl;
	t_equation l = showmatches(left);
	// std::cout << "right matches: " << std::endl;
	t_equation r = showmatches(right);	

	t_equation	full = reducepoly(l, r);

	full.o_it = full.oper.begin();
	full.v_it = full.vars.begin();
	while (full.o_it != full.oper.end() && full.v_it != full.vars.end()) {
		std::cout << *(full.v_it) << " " << *(full.o_it) << " ";
		if (full.o_it != full.oper.end()) 
			full.o_it++;
		if (full.v_it != full.vars.end()) 
			full.v_it++;
	}
	std::cout << "= 0" << std::endl;
}

int		main( void ) {
	std::string		poly1("5 + 4 * X + X^2= X^2");
	std::string		poly2("5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0");
	std::string		poly3("5 * X^0 + 4 * X^1 = 4 * X^0");
	std::string		poly4("8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0");
	// std::string		poly5("8X^2 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0");

	parsepoly(poly1);
	parsepoly(poly2);
	parsepoly(poly3);
	parsepoly(poly4);
	// parsepoly(poly5);
}