/*
 * Circle.h
 *
 *  Created on: 22 de jun. de 2023
 *      Author: affon
 */

#ifndef SHAPES_CIRCLE_H_
#define SHAPES_CIRCLE_H_

#include "Shape.h"

class Circle: public Shape
{
public:
	Circle();
	Circle(const Vec2D& center, float radius);

	virtual Vec2D GetCenterPoint() const override { return mPoints[0]; }
	inline float GetRadius() const { return mRadius; }
	inline void setRadius(float radius) { mRadius = radius; }
	inline void MoveTo(const Vec2D& position) { mPoints[0] = position; }

	bool Intersects(const Circle& otherCircle) const;
	bool ContainsPoint(const Vec2D& point) const;

private:
	float mRadius;
};

#endif /* SHAPES_CIRCLE_H_ */
