/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:55:36 by agautier          #+#    #+#             */
/*   Updated: 2021/12/20 18:54:30 by agautier         ###   ########.fr       */
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
	if (this->numbers.size() >= this->size)
		throw Full();
	this->numbers.push_back(n);
}

/*
**	Add a range of numbers in numbers vector.
*/
void Span::addNumbers(std::vector<int>::iterator begin,
					  std::vector<int>::iterator end) {
	if (this->numbers.size() + std::distance(begin, end) > this->size)
		throw Full();
	this->numbers.insert(this->numbers.end(), begin, end);
}

/*
**	Return the shortest span between all the numbers.
*/
unsigned int Span::shortestSpan(void) const {
	if (this->numbers.size() <= 1)
		throw NotEnoughNumber();

	unsigned int span = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::const_iterator it = this->numbers.begin();
		 it != this->numbers.end();
		 it++) {
		for (std::vector<int>::const_iterator it2 = this->numbers.begin();
			 it2 != this->numbers.end();
			 it2++) {
			if (it != it2
				&& static_cast<unsigned int>(std::abs(*it - *it2)) < span)
				span = std::abs(*it - *it2);
		}
	}
	return (span);
}

/*
**	Return the longest span between all the numbers.
*/
unsigned int Span::longestSpan(void) const {
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
	return ("not enough number in span");
}

/*
**	Exception: notEnoughNumber
*/
char const* Span::Full::what(void) const throw() { return ("span is full"); }
