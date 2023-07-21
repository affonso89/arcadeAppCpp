/*
 * InputAction.h
 *
 *  Created on: 21 de jul. de 2023
 *      Author: affon
 */

#ifndef INPUT_INPUTACTION_H_
#define INPUT_INPUTACTION_H_

#include <functional>
#include <stdint.h>

using InputKey = uint8_t;
using InputState = uint8_t;

using InputAction = std::function<void(uint32_t dt, InputState)>;

struct ButtonAction
{
	InputKey key;
	InputAction action;
};


#endif /* INPUT_INPUTACTION_H_ */
