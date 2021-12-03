/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:30:47 by agautier          #+#    #+#             */
/*   Updated: 2021/12/03 16:27:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void) {
	int myints[] = {1, 2, 3, 4, 5};

	std::vector<int> vec(myints, myints + sizeof(myints) / sizeof(int));
	try {
		std::cout << *easyfind(vec, 3) << std::endl;
	} catch (std::exception const& e) { std::cerr << e.what() << std::endl; }

	std::list<int> lst(myints, myints + sizeof(myints) / sizeof(int));
	try {
		std::cout << *easyfind(lst, 2) << std::endl;
		std::cout << *easyfind(lst, 12) << std::endl;
	} catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
	return (0);
}
