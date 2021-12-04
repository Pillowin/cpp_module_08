/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:06 by agautier          #+#    #+#             */
/*   Updated: 2021/12/04 18:36:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	MutanStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(12);
	mstack.push(987);
	mstack.push(29);
	mstack.push(1);
	mstack.push(-123);
	mstack.push(79888);
	mstack.push(2021);
	mstack.push(0);

	MutanStack<int>::iterator it  = mstack.begin();
	MutanStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (EXIT_SUCCESS);
}
