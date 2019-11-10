/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:23:27 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/10 17:08:36 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

int main(int argc, char **argv)
{
	try
	{
		Parser parser;	
		if (argc == 1)
			parser.read_terminal();
		else if (argc == 2)
			parser.read_file(argv[1]);
		else
		{
			return (1);
		}
			
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}