/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:16:30 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/21 16:42:06 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORYMETHOD_HPP
# define FACTORYMETHOD_HPP

#include "IOperand.hpp"
#include <vector>

class Factory
{

private:

    typedef std::vector<IOperand const *(Factory::*)(std::string const & value) const> point_arr;
    static point_arr _parr;
    
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

public:

    Factory();
    Factory(Factory const &);
    Factory & operator=(Factory const &);  
    ~Factory();

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    
};

#endif