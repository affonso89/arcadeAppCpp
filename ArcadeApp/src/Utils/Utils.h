/*
 * Utils.h
 *
 *  Created on: 30 de mai. de 2023
 *      Author: F46943A
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);

bool isGreaterThanOrEqual(float x, float y);

bool isLessThanOrEqual(float x, float y);

float MillisecondsToSeconds(unsigned int milliseconds);

#endif /* UTILS_UTILS_H_ */
