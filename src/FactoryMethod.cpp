/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:15:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/21 18:19:25 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FactoryMethod.hpp"

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

IOperand const * createOperand( eOperandType type, std::string const & value ) const
{
    
}

IOperand const * Factory::createInt8( std::string const & value ) const
{

}

IOperand const * Factory::createInt16( std::string const & value ) const
{
    
}

IOperand const * Factory::createInt32( std::string const & value ) const 
{
    
}

IOperand const * Factory::createFloat( std::string const & value ) const 
{
    
}

IOperand const * Factory::createDouble( std::string const & value ) const 
{

}
