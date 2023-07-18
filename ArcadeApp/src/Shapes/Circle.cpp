/*
 * Circle.cpp
 *
 *  Created on: 22 de jun. de 2023
 *      Author: affon
 */

#include "Circle.h"
#include "../Utils/Utils.h"

Circle::Circle(): Circle(Vec2D::Zero, 0)
{

}

Circle::Circle(const Vec2D& center, float radius): mRadius(radius)
{
	mPoints.push_back(center);
}

bool Circle::Intersects(const Circle& otherCircle) const
{
	return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (mRadius + otherCircle.mRadius);
}

bool Circle::ContainsPoint(const Vec2D& point) const
{
	return isLessThanOrEqual(GetCenterPoint().Distance(point), mRadius);
}
