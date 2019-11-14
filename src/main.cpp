/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:23:27 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/12 15:12:49 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

int main(int argc, char **argv)
{
	try
	{
		Parser parser;	
		if (argc == 1)
			parser.read_instruct();
		else if (argc == 2)
			parser.read_instruct(argv[1]);
		else
			throw Ex_BadParams();
			
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}