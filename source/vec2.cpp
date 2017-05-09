#include "vec2.hpp"
#include <cmath>
#include <iostream>

Vec2::Vec2(float a, float b) :
	x_{a},
	y_{b} {}

Vec2::Vec2() :
	x_{0.0f},
	y_{0.0f} {}


Vec2& Vec2::operator+=(Vec2 const& v)
{
	x_ += v.x_;
	y_ += v.y_;

	return *this;
}

Vec2 & Vec2::operator -= (Vec2 const & v)
{
	x_ -= v.x_;
	y_ -= v.y_;

	return *this;
}

Vec2 & Vec2::operator *= (float s)
{
	x_ *= s;
	y_ *= s;

	return *this;
}

Vec2 & Vec2::operator /=( float s )
{
	if (s == 0)
	{
		std::cout << "DIVISION BY ZERO";
		return *this;
	}
	else
	{
		x_ /= s;
		y_ /= s;
	}
	return *this;
}

Vec2 operator + ( Vec2 const & u , Vec2 const & v )
{
	Vec2 result{};
	result.x_ = u.x_ + v.x_;
	result.y_ = u.y_ + v.y_;
	return result;
}

Vec2 operator - ( Vec2 const & u , Vec2 const & v )
{
	Vec2 result{};
	result.x_ = u.x_ - v.x_;
	result.y_ = u.y_ - v.y_;
	return result;
}

Vec2 operator * (Vec2 const& v, float s) {
	return Vec2 {v.x_ * s, v.y_ * s};
}

Vec2 operator / ( Vec2 const & v , float s )
{
	if (s == 0)
	{
		std::cout << "DIVISION BY ZERO";
		return v;
	}
	else
	{
		Vec2 result{};
		result.x_ = v.x_ /s;
		result.y_ = v.y_ /s;
		return result;
	}
}

Vec2 operator * ( float s , Vec2 const & v )
{
	return v*s;
}