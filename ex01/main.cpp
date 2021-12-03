/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:54:55 by agautier          #+#    #+#             */
/*   Updated: 2021/12/03 22:55:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main(void) {
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span span(5);

	try {
		span.addNumber(5);
		span.addNumber(2);
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
