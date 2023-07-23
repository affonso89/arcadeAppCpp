/*
 * Utils.cpp
 *
 *  Created on: 30 de mai. de 2023
 *      Author: F46943A
 */

#include "Utils.h"
#include <cmath>

bool IsEqual(float x, float y) {
	return fabsf(x - y) < EPSILON;
}

bool isGreaterThanOrEqual(float x, float y) {
	return x > y || IsEqual(x, y);
}

bool isLessThanOrEqual(float x, float y) {
	return x < y || IsEqual(x, y);
}

float MillisecondsToSeconds(unsigned int milliseconds)
{
	return static_cast<float>(milliseconds) / 1000.0f;
}
