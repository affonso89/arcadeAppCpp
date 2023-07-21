/*
 * GameController.cpp
 *
 *  Created on: 21 de jul. de 2023
 *      Author: affon
 */

#include "GameController.h"
#include <SDL2/SDL.h>

GameController::GameController()
{

}

InputAction GameController::GetActionForKey(InputKey key)
{
	for(const auto& buttonAction: mButtonActions)
	{
		if(key == buttonAction.key)
		{
			return buttonAction.action;
		}
	}

	return [](uint32_t, InputState){};
}

void GameController::AddInputAtionForKey(const ButtonAction& buttonAction)
{
	mButtonActions.push_back(buttonAction);
}

void GameController::ClearAll()
{
	mButtonActions.clear();
}

bool GameController::IsPressed(InputState state)
{
	return state == SDL_PRESSED;
}

bool GameController::IsReleased(InputState state)
{
	return state == SDL_RELEASED;
}

InputKey GameController::ActionKey()
{
	return static_cast<InputKey>(SDLK_a);
}

InputKey GameController::CancelKey()
{
	return static_cast<InputKey>(SDLK_s);
}

InputKey GameController::LeftKey()
{
	return static_cast<InputKey>(SDLK_LEFT);
}

InputKey GameController::RightKey()
{
	return static_cast<InputKey>(SDLK_RIGHT);
}

InputKey GameController::UpKey()
{
	return static_cast<InputKey>(SDLK_UP);
}

InputKey GameController::DownKey()
{
	return static_cast<InputKey>(SDLK_DOWN);
}

