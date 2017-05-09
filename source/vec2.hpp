
#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2
{
	Vec2();
	Vec2(float, float);

	float x_;
	float y_; 
	Vec2 & operator += (Vec2 const& v);
	Vec2 & operator -= (Vec2 const & v);
	Vec2 & operator *= (float s);
	Vec2 & operator /= (float s);
};

Vec2 operator + (Vec2 const & u, Vec2 const & v);
Vec2 operator - (Vec2 const & u, Vec2 const & v);
Vec2 operator * (Vec2 const& v, float s);
Vec2 operator / (Vec2 const& v, float s);
Vec2 operator * (float s, Vec2 const& v);


#endif