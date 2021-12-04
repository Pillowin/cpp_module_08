/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:07:27 by agautier          #+#    #+#             */
/*   Updated: 2021/12/04 18:38:09 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
#define MUTAN_STACK_HPP

#include <iterator>
#include <stack>

template<typename T> class MutanStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type container_type;
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::value_type value_type;
		typedef typename std::stack<T>::size_type size_type;

		MutanStack(void) : std::stack<T>() {}
		MutanStack(MutanStack const& rhs) : std::stack<T>(rhs) { *this = rhs; }

		~MutanStack(void) {}

		iterator begin(void) { return (this->c.begin()); }
		iterator end(void) { return (this->c.end()); }
		iterator rbegin(void) { return (this->c.rbegin()); }
		iterator rend(void) { return (this->c.rend()); }

		MutanStack& operator=(MutanStack const& rhs) {
			if (this == &rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		}
};

#endif

