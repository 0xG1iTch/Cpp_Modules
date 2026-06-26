/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:46:06 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/23 18:25:18 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): value(0) {}

Fixed::Fixed(const Fixed& other)
{
    this->value = other.value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::Fixed(const int n) : value(n << fractionalBits) {} // n * 2^8

Fixed::Fixed(const float f)
{
    value = static_cast<int>(std::roundf(f * (1 << fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream &os, Fixed const &f)
{
    os << f.toFloat();
    return os;
}

// comparisons
bool Fixed::operator>(Fixed const &other) const { return this->value > other.value; }
bool Fixed::operator<(Fixed const &other) const { return this->value < other.value; }
bool Fixed::operator>=(Fixed const &other) const { return this->value >= other.value; }
bool Fixed::operator<=(Fixed const &other) const { return this->value <= other.value; }
bool Fixed::operator==(Fixed const &other) const { return this->value == other.value; }
bool Fixed::operator!=(Fixed const &other) const { return this->value != other.value; }

// arithmetic
Fixed Fixed::operator+(Fixed const &other) const
{
    Fixed res;
    res.setRawBits(this->value + other.value);
    return res;
}

Fixed Fixed::operator-(Fixed const &other) const
{
    Fixed res;
    res.setRawBits(this->value - other.value);
    return res;
}

Fixed Fixed::operator*(Fixed const &other) const
{
    Fixed res;
    int64_t tmp = (int64_t)this->value * (int64_t)other.value;
    tmp = tmp / (1 << fractionalBits);
    res.setRawBits((int)tmp);
    return res;
}

Fixed Fixed::operator/(Fixed const &other) const
{
    Fixed res;
    int64_t tmp = (int64_t)this->value * (1 << fractionalBits);
    tmp = tmp / (int64_t)other.value;
    res.setRawBits((int)tmp);
    return res;
}
// increment / decrement
Fixed &Fixed::operator++()
{
    ++value;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(this->value);
    return tmp;
}

Fixed &Fixed::operator--()
{
    --value;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this); 
    --(this->value);
    return tmp;
}

// min / max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.value < b.value) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.value < b.value) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.value > b.value) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.value > b.value) ? a : b;
}
