/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:55:35 by agautier          #+#    #+#             */
/*   Updated: 2021/12/03 22:47:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span {
	public:
		Span(unsigned int n = 0);
		Span(Span const& rhs);

		virtual ~Span(void);

		void addNumber(int n);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

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
