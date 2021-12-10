/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:06 by agautier          #+#    #+#             */
/*   Updated: 2021/12/10 17:42:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	{
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
	}

	std::cout << std::endl << "My tests ------------" << std::endl << std::endl;

	{
		MutanStack<std::string> mutan_stack;

		std::cout << "mutan_stack is "
				  << (mutan_stack.empty() ? "empty." : "not empty.")
				  << std::endl;

		mutan_stack.push("Hello");
		mutan_stack.push(" ");
		mutan_stack.push("my");
		mutan_stack.push(" ");
		mutan_stack.push("name");
		mutan_stack.push(" ");
		mutan_stack.push("is");
		mutan_stack.push(" ");
		mutan_stack.push("Antoine");

		std::cout << "mutan_stack is "
				  << (mutan_stack.empty() ? "empty." : "not empty.")
				  << std::endl;

		std::cout << "mutan_stack size is " << mutan_stack.size() << "."
				  << std::endl;

		std::cout << "mutan_stack top elem is '" << mutan_stack.top() << "'."
				  << std::endl;

		for (MutanStack<std::string>::iterator it = mutan_stack.begin();
			 it != mutan_stack.end();
			 it++)
			std::cout << *it;
		std::cout << std::endl;

		mutan_stack.pop();
		mutan_stack.push("toto");

		for (MutanStack<std::string>::iterator it = mutan_stack.begin();
			 it != mutan_stack.end();
			 it++)
			std::cout << *it;
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
