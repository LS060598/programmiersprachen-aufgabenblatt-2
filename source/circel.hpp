
#ifndef CIRCEL_HPP
#define CIRCEL_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle
{
public:
	Circle (Vec2 const& center, float radius, Color const& color);
	
	//Getter
	Vec2 const& getCenter() const; 
	float getRadius() const;
	Color const& getColor() const; 
	//Circumference
	float circumference() const; 
	//draw
	void draw(Window const& window);

	//draw with explicit color
	void draw(Window const& window, Color const& color);

	
private:
	Vec2 center_;
	float radius_;
	Color color_;
};

#endif
