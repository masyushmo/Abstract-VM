/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:44:46 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/21 16:59:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"
#include <string>

template <typename T>
class Operand : public IOperand
{
    
private:
    
    T _value;
    eOperandType _type;
    std::string str;

public:
    
    Operan<T>();
    Operand<T>(Operand const &);
    ~Operand<T>();

    Operand<T>&  operator=(Operand<T> const &);

    IOperand const * operator+( IOperand const & rhs ) const;
    IOperand const * operator-( IOperand const & rhs ) const;
    IOperand const * operator*( IOperand const & rhs ) const;
    IOperand const * operator/( IOperand const & rhs ) const;
    IOperand const * operator%( IOperand const & rhs ) const;
    
    std::string const & toString( void ) const;
};

#endif