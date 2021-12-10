/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:55:35 by agautier          #+#    #+#             */
/*   Updated: 2021/12/10 17:24:31 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class Span {
	public:
		Span(unsigned int n = 0);
		Span(Span const& rhs);

		virtual ~Span(void);

		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		Span& operator=(Span const& rhs);

		class NotEnoughNumber: public std::exception {
			public:
				char const* what(void) const throw();
		};
		class Full: public std::exception {
			public:
				char const* what(void) const throw();
		};

	private:
		unsigned int size;
		std::vector<int> numbers;
};

#endif
