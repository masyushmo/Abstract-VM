/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:44:46 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 13:01:50 by mmasyush         ###   ########.fr       */
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
    
    Operand<T>();
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
