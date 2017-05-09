#ifndef RECTANGEL_HPP
#define RECTANGEL_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
public:
	Rectangle (Vec2 const& min, Vec2 const& max, Color const& color);
	
	//Getter
	Vec2 const& getMin() const; 
	Vec2 const& getMax() const;
	Color const& getColor() const; 

	//Circumference
	float circumference() const; 

	void draw(Window const& window)const;
	void draw(Window const& window, Color const& c)const;

private:
	Vec2 min_;
	Vec2 max_;
	Color color_;
};

#endif
