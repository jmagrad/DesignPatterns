#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

enum class PointType
{
	cartesian,
	polar
};

/*
//bad implementation
class Point
{
public:
	//Point(float x, float y) : x(x), y(y) {}

	//confusing for inputs? what is x what is rho etc
	Point(float a, float b, PointType type = PointType::cartesian)
	{
		if (type == PointType::cartesian)
		{
			x = a;
			y = b;
		}
		else {
			x = a * cos(b);
			y = a * sin(b);
		}
	}
private:
	float x, y;
};
*/

class Point
{
	Point(float x, float y) :x(x), y(y) {}
public:
	float x, y;

	static Point NewCartesian(float x, float y)
	{
		return { x,y };
	}

	static Point NewPolar(float r, float theta)
	{
		return { r * cos(theta),r * sin(theta) };
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point)
	{
		os << "x: " << point.x << "y: " << point.y;
		return os;
	}
};

int main1()
{
	auto p = Point::NewPolar(5, .5);
	return 0;
}