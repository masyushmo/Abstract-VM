/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:44:46 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 18:55:19 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"
#include "FactoryMethod.hpp"
#include "Exept.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

template <typename T>
class Operand : public IOperand
{
    
private:
    
    T _value;
    eOperandType _type;
    int _precision;
    std::string _str;

public:
    
    Operand<T>();
    Operand<T>(T value);
    Operand<T>(Operand const &);
    ~Operand<T>();

    Operand<T>&  operator=(Operand<T> const &);

    int getPrecision( void ) const;
    eOperandType getType( void ) const;

    IOperand const * operator+( IOperand const & rhs) const;
    IOperand const * operator-( IOperand const & rhs) const;
    IOperand const * operator*( IOperand const & rhs) const;
    IOperand const * operator/( IOperand const & rhs ) const;
    IOperand const * operator%( IOperand const & rhs ) const;
    
    std::string const & toString( void ) const;
    void    setType();
    void    setStr();
};

#endif
