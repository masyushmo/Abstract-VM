/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:15:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/27 19:36:05 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FactoryMethod.hpp"
#include "../headers/Exept.hpp"
#include "../headers/IOperand.hpp"

std::vector<Factory::_vecType> Factory::_vecA = { &Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};

Factory::Factory() {}

Factory::Factory(Factory const &cpy)
{
    *this = cpy;
}

Factory& Factory::operator=(Factory const &)
{
    return *this;
}

Factory::~Factory() {}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const * b = (this->*(_vecA.at(type)))(value);
	std::cout << "FSFSDFSDFSD" << b->toString() << "fff'" <<  std::endl;
	return ((this->*(_vecA.at(type)))(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
    long long num = std::stoll(value);
	
	try
	{
		if (num > INT8_MAX)
			throw Ex_Overflow();
		else if (num < INT8_MIN)
			throw Ex_Underflow();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (new Operand<int8_t>(static_cast<int8_t>(num))); 
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
   	long long num = std::stoll(value);

	try
	{
		if (num > INT16_MAX)
			throw Ex_Overflow();
		else if (num < INT16_MIN)
			throw Ex_Underflow();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (new Operand<int16_t>(static_cast<int16_t>(num))); 
}  

IOperand const * Factory::createInt32( std::string const & value ) const 
{
    long long num = std::stoll(value);

	try
	{
		if (num > INT32_MAX)
			throw Ex_Overflow();
		else if (num < INT32_MIN)
			throw Ex_Underflow();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (new Operand<int32_t>(static_cast<int32_t>(num)));
}

IOperand const * Factory::createFloat( std::string const & value ) const 
{
    long double num = std::stold(value);

	try
	{
		if (num > FLT_MAX)
			throw Ex_Overflow();
		else if (num < FLT_MIN)
			throw Ex_Underflow();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (new Operand<float>(static_cast<float>(num))); 
}

IOperand const * Factory::createDouble( std::string const & value ) const 
{
    long double num = std::stold(value);

	try
	{
		if (num > DBL_MAX)
			throw Ex_Overflow();
		else if (num < DBL_MIN)
			throw Ex_Underflow();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (new Operand<double>(static_cast<double>(num)));
}
