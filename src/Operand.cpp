/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:46:16 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/23 15:42:20 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Operand.hpp"

template < typename T >
Operand<T>::Operand() {}

template < typename T >
Operand<T>::Operand(T value)
{
    _value = value;
    _type = setType();
    _str = toString();
}

template < typename T >
Operand<T>::Operand(Operand<T> const & src) { *this = src; }

template < typename T >
Operand<T> &	Operand<T>::operator=(Operand<T> const & src)
{
	_value = src._value;
	_type = src.getType();
	_str = src.toString();
    _precision = src.getPrecision();
	return *this;
}

template < typename T >
Operand<T>::~Operand() {}

template < typename T >
int Operand<T>::getPrecision() const { return _precision; }

template < typename T >
eOperandType Operand<T>::getType() const { return _type; }

template < typename T >
std::string const & Operand<T>::toString() const { return _str; }

template <typename T >
void Operand<T>::setType()
{
    if (typeid(int8_t) == typeid(T))
    {
        _type = Int8;
        _precision = 0;
    }
	else if (typeid(int16_t) == typeid(T))
    {
        _type = Int16;
        _precision = 0;
    }
	else if (typeid(int32_t) == typeid(T))
    {
        _type = Int32;
        _precision = 0;
    }
	else if (typeid(float) == typeid(T))
    {
        _type = Float;
        _precision = 7;
    }
	else
    {
        _type = Double;
        _precision = 14;
    }
}

template <typename T >
void Operand<T>::setStr()
{
    if (_precision == 7 || _precision == 14)
    {
        std::stringstream strs;
        strs << std::setprecision(_precision) << _value;
        _str = strs.str();
    }
    else
        _str = std::to_string(_value);
}

template <typename T >
IOperand const * Operand<T>::operator+(IOperand const & rhs) const
{
    eOperandType top = std::max(_type, rhs.getType());
    Factory fac;

    if (top >= Float)
        return (fac.createOperand(top, \
            std::to_string(static_cast<long double>(_value) + std::stold(rhs.toString()))));
    else
        return (fac.createOperand(top, \
            std::to_string(static_cast<long long>(_value) + std::stoll(rhs.toString()))));
}

template <typename T >
IOperand const * Operand<T>::operator-(IOperand const & rhs) const
{
    eOperandType top = std::max(_type, rhs.getType());
    Factory fac;

    if (top >= Float)
        return (fac.createOperand(top, \
            std::to_string(static_cast<long double>(_value) - std::stold(rhs.toString()))));
    else
        return (fac.createOperand(top, \
            std::to_string(static_cast<long long>(_value) - std::stoll(rhs.toString()))));
}

template <typename T >
IOperand const * Operand<T>::operator*(IOperand const & rhs) const
{
    eOperandType top = std::max(_type, rhs.getType());
    Factory fac;

    if (top >= Float)
        return (fac.createOperand(top, \
            std::to_string(static_cast<long double>(_value) * std::stold(rhs.toString()))));
    else
        return (fac.createOperand(top, \
            std::to_string(static_cast<long long>(_value) * std::stoll(rhs.toString()))));
}

template <typename T >
IOperand const * Operand<T>::operator/(IOperand const & rhs) const
{
    try
    {
        if (std::stold(rhs.toString()) == 0)
		    throw Ex_DivByZero();
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    eOperandType top = std::max(_type, rhs.getType());
    Factory fac;

    if (top >= Float)
        return (fac.createOperand(top, \
            std::to_string(static_cast<long double>(_value) / std::stold(rhs.toString()))));
    else
        return (fac.createOperand(top, \
            std::to_string(static_cast<long long>(_value) / std::stoll(rhs.toString()))));
}

template <typename T >
IOperand const * Operand<T>::operator%(IOperand const & rhs) const
{
    try
    {
        if (std::stold(rhs.toString()) == 0)
		    throw Ex_DivByZero();
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    eOperandType top = std::max(_type, rhs.getType());
    Factory fac;

    if (top >= Float)
        return (fac.createOperand(top, \
            std::to_string(fmod(static_cast<long double>(_value), std::stold(rhs.toString())))));
    else
        return (fac.createOperand(top, \
            std::to_string(static_cast<long long>(_value) % std::stoll(rhs.toString()))));
}
