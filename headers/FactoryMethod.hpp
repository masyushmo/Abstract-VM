/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:16:30 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/01 18:21:26 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORYMETHOD_HPP
# define FACTORYMETHOD_HPP

#include "IOperand.hpp"
#include "Operand.hpp"
#include <vector>
#include <limits>
#include <cstdint>
#include <float.h>

class Factory
{

private:

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    typedef decltype(&Factory::createDouble) _vecType;
    static std::vector<_vecType> _vecA;

public:

    Factory();
    Factory(Factory const &);
    Factory & operator=(Factory const &);  
    ~Factory();

    IOperand const * createOperand(eOperandType type, std::string const & value ) const;
    
};

#endif