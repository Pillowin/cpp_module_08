/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:55:36 by agautier          #+#    #+#             */
/*   Updated: 2021/12/03 22:53:41 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
**	Default and parametric constructor.
*/
Span::Span(unsigned int n) : size(n), numbers(0) {}

/*
**	Copy constructor.
*/
Span::Span(Span const& rhs) { *this = rhs; }

/*
**	Destructor.
*/
Span::~Span(void) {}

/*
**	Add a single number n in numbers vector.
*/
void Span::addNumber(int n) {
	if (this->numbers.size() > this->size)
		throw Full();
	this->numbers.push_back(n);
}

/*
**	Return the shortest span between all the numbers.
*/
unsigned int Span::shortestSpan(void) {
	if (this->numbers.size() <= 1)
		throw NotEnoughNumber();
	std::vector<int>::iterator it
		= std::min_element(this->numbers.begin(), this->numbers.end());
	int min1 = *it;
	this->numbers.erase(it);
	int min2 = *std::min_element(this->numbers.begin(), this->numbers.end());
	this->numbers.insert(it, min1);
	return (min2 - min1);
}

/*
**	Return the longest span between all the numbers.
*/
unsigned int Span::longestSpan(void) {
	if (this->numbers.size() <= 1)
		throw NotEnoughNumber();
	return (*std::max_element(this->numbers.begin(), this->numbers.end())
			- *std::min_element(this->numbers.begin(), this->numbers.end()));
}

/*
**	Assignment operator.
*/
Span& Span::operator=(Span const& rhs) {
	if (this == &rhs)
		return (*this);
	this->size	  = rhs.size;
	this->numbers = rhs.numbers;
	return (*this);
}

/*
**	Exception: notEnoughNumber
*/
char const* Span::NotEnoughNumber::what(void) const throw() {
	return ("Not enough number in span");
}

/*
**	Exception: notEnoughNumber
*/
char const* Span::Full::what(void) const throw() {
	return ("Not enough number in span");
}
