/*
 * Utils.h
 *
 *  Created on: 30 de mai. de 2023
 *      Author: F46943A
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <string>

static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);

bool isGreaterThanOrEqual(float x, float y);

bool isLessThanOrEqual(float x, float y);

float MillisecondsToSeconds(unsigned int milliseconds);

unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c);

bool StringCompare(const std::string& a, const std::string& b);

float Clamp(float val, float min, float max);

struct Size
{
	unsigned int width = 0, height = 0;
};

#endif /* UTILS_UTILS_H_ */
