/*
 * Shape.cpp
 *
 *  Created on: 18 de jun. de 2023
 *      Author: affon
 */

#include "Shape.h"

void Shape::MoveBy(const Vec2D& deltaOffset)
{
	for(Vec2D& point : mPoints)
	{
		point = point + deltaOffset;
	}
}


