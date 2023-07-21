/*
 * GameController.h
 *
 *  Created on: 21 de jul. de 2023
 *      Author: affon
 */

#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include "InputAction.h"
#include <vector>

class GameController
{
public:
	GameController();
	InputAction GetActionForKey(InputKey key);
	void AddInputAtionForKey(const ButtonAction& buttonAction);
	void ClearAll();

	static bool IsPressed(InputState state);
	static bool IsReleased(InputState state);
	static InputKey ActionKey();
	static InputKey CancelKey();
	static InputKey LeftKey();
	static InputKey RightKey();
	static InputKey UpKey();
	static InputKey DownKey();

private:
	std::vector<ButtonAction> mButtonActions;
};


#endif /* INPUT_GAMECONTROLLER_H_ */
