// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------

#ifndef	XPCC__POINT_HPP
	#error	"Don't include this file directly, use 'point.hpp' instead!"
#endif

// ----------------------------------------------------------------------------
template<typename T>
xpcc::Point<T>::Point() :
	x(), y()
{
}

template<typename T>
xpcc::Point<T>::Point(const T& x, const T& y) : 
	x(x), y(y)
{
}

// ----------------------------------------------------------------------------
template<typename T>
void
xpcc::Point<T>::setX(const T& value)
{
	this->x = value;
}

// ----------------------------------------------------------------------------
template<typename T>
void
xpcc::Point<T>::setY(const T& value)
{
	this->y = value;
}

// ----------------------------------------------------------------------------
template<typename T>
void
xpcc::Point<T>::set(const T& x, const T& y)
{
	this->x = x;
	this->y = y;
}

// ----------------------------------------------------------------------------
template<typename T>
const T&
xpcc::Point<T>::getX() const
{
	return this->x;
}

// ----------------------------------------------------------------------------
template<typename T>
const T&
xpcc::Point<T>::getY() const
{
	return this->y;
}

// ----------------------------------------------------------------------------
template<typename T>
T
xpcc::Point<T>::getLength() const
{
	float tx = this->x;
	float ty = this->y;
	
	return std::sqrt(tx*tx + ty*ty);
}

// ----------------------------------------------------------------------------
template<typename T>
T
xpcc::Point<T>::getManhattanLength() const
{
	return (std::abs(this->x) + std::abs(this->y));
}

// ----------------------------------------------------------------------------
template<typename T>
xpcc::Angle
xpcc::Point<T>::getAngle() const
{
	return std::atan2(y, x);
}

// ----------------------------------------------------------------------------
template<typename T>
xpcc::Point<T>&
xpcc::Point<T>::normalize()
{
	T length = this->getLength();
	
	this->x = this->x / length;
	this->y = this->y / length;
	
	return *this;
}

// ----------------------------------------------------------------------------
template<typename T>
template<typename U>
xpcc::Point<T>&
xpcc::Point<T>::scale(const U& factor)
{
	this->x = this->x * factor;
	this->y = this->y * factor;

	return *this;
}

// ----------------------------------------------------------------------------
template<typename T>
xpcc::Point<T>&
xpcc::Point<T>::rotate(const Angle& phi)
{
	float c = cos(phi).toFloat();
	float s = sin(phi).toFloat();
	
	// without rounding the result might be false for T = integer
	T tx =    round(c * this->x - s * this->y);
	this->y = round(s * this->x + c * this->y);
	this->x = tx;
	
	return *this;
}

// ----------------------------------------------------------------------------
template<typename T>
xpcc::Point<T>&
xpcc::Point<T>::operator += (const Point &other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

// ----------------------------------------------------------------------------	
template<typename T>
xpcc::Point<T>&
xpcc::Point<T>::operator -= (const Point &other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

// ----------------------------------------------------------------------------
template<typename T> template<typename U>
xpcc::Point<T>::operator Point<U>() const
{
	return Point<U>(this->x, this->y);
}

// ----------------------------------------------------------------------------

template<typename U>
xpcc::Point<U>
xpcc::operator - (const Point<U> &a)
{
	return Point<U>(-a.x, -a.y);
}

template<typename U>
xpcc::Point<U>
xpcc::operator - (const Point<U> &a, const Point<U> &b)
{
	return Point<U>(a.x - b.x, a.y - b.y);
}

template<typename U, typename V>
xpcc::Point<U>
xpcc::operator - (const Point<U> &a, const Point<V> &b)
{
	return Point<U>(a.x - b.x, a.y - b.y);
}

template<typename U>
xpcc::Point<U>
xpcc::operator + (const Point<U> &a, const Point<U> &b)
{
	return Point<U>(a.x + b.x, a.y + b.y);
}

template<typename U,typename V>
xpcc::Point<U>
xpcc::operator + (const Point<U> &a, const Point<V> &b)
{
	return Point<U>(a.x + b.x, a.y + b.y);
}

template<typename U>
bool
xpcc::operator == (const Point<U> &a, const Point<U> &b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

template<typename U>
bool
xpcc::operator != (const Point<U> &a, const Point<U> &b)
{
	return ((a.x != b.x) || (a.y != b.y));
}

// ----------------------------------------------------------------------------
template<typename U, typename V>
U
xpcc::scalar(const xpcc::Point<U> &a, const xpcc::Point<V> &b)
{
	return (a.x * b.x + a.y * b.y);
}

// ----------------------------------------------------------------------------
template <typename U>
xpcc::IOStream&
xpcc::operator <<( xpcc::IOStream& s, const xpcc::Point<U>& c)
{
	s << "x=" << c.x << ", y=" << c.y;
	return s;
}
