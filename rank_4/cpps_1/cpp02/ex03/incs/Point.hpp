#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public: 

		Point();
		Point(const Point &obj);
		Point(const float x, const float y);
		Point &operator=(const Point &obj);
		~Point();
		Fixed getX() const;
		Fixed getY() const;

	private:

		Fixed _x;
		Fixed _y;
};

Fixed area(Point const a, Point const b, Point const c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
