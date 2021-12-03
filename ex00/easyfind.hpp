/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:38 by agautier          #+#    #+#             */
/*   Updated: 2021/12/03 16:18:55 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_HPP
#define EASYFIND_HPP_HPP

#include <algorithm>
#include <iostream>

class notFound: public std::exception {
	public:
		const char* what(void) const throw() { return "not found"; }
};

template<typename T>
typename T::iterator easyfind(T& container, int const& to_find) {
	typename T::iterator it = container.begin();
	for (; it != container.end(); ++it)
		if (*it == to_find)
			return it;
	throw notFound();
	return it;
}

#endif
