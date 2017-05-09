#include "circel.hpp"
#include "vec2.hpp"
#include "Mat2.hpp"
#include "color.hpp"
#include "window.hpp"

#include <cmath>

//Constructor
Circle::Circle (Vec2 const& center, float radius, Color const& color):
	center_{center},
	radius_{radius},
	color_{color} {}

//Getter
Vec2 const& Circle::getCenter() const 
{
	return center_;
}

float Circle::getRadius() const
{
	return radius_;
}

Color const& Circle::getColor() const{ 
	return color_;
}

//Circumference
float Circle::circumference() const
{
	return (float)(2.0f * M_PI * radius_);
}

//draw
void Circle::draw(Window const& window)
{
	for (int i = 1; i<=360; ++i)
	{
		Vec2 p0 {radius_, 0.0f};
		//2PI = Vollwinkel -> * i/360 = 360 Segmente des Kreises
		float x = (float)(2.0f * M_PI * (i/360.0f));
		Mat2 rotMat = make_rotation_mat2 (x);
		// Mat2 rotMat2 = make_rotation_mat2(2 * M_PI * (i+1/360));
		Vec2 p1 = rotMat * p0;
		Vec2 p2 = rotMat * p1;
		window.draw_line(p1.x_, p1.y_, p2.x_, p2.y_, color_.r_, color_.g_, color_.b_);
	}
}

//draw with explicit color
void Circle::draw(Window const& window, Color const& color)
{
	
}