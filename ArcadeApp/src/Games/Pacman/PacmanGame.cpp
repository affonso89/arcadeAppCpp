/*
 * PacmanGame.cpp
 *
 *  Created on: 17 de dez. de 2023
 *      Author: F46943A
 */

#include "PacmanGame.h"
#include "../../App/App.h"
#include "PacmanGameUtils.h"

void PacmanGame::Init(GameController& controller)
{
	mPacmanSpriteSheet.Load("PacmanSprites");

	mPacman.Init(mPacmanSpriteSheet, App::Singleton().GetBasePath() + "Assets/Pacman_animations.txt", Vec2D(108, 204), PACMAN_MOVEMENT_SPEED, false);

	mLevel.Init(App::Singleton().GetBasePath() + "Assets/Pacman_level.txt", &mPacman);

	ResetGame();

	ButtonAction leftAction;
	leftAction.key = GameController::LeftKey();
	leftAction.action = [this](uint32_t dt, InputState state)
		{
			HandleGameControllerState(dt, state, PACMAN_MOVEMENT_LEFT);
		};
	controller.AddInputActionForKey(leftAction);

	ButtonAction rightAction;
	rightAction.key = GameController::RightKey();
	rightAction.action = [this](uint32_t dt, InputState state)
		{
			HandleGameControllerState(dt, state, PACMAN_MOVEMENT_RIGHT);
		};
	controller.AddInputActionForKey(rightAction);

	ButtonAction upAction;
	upAction.key = GameController::UpKey();
	upAction.action = [this](uint32_t dt, InputState state)
		{
			HandleGameControllerState(dt, state, PACMAN_MOVEMENT_UP);
		};
	controller.AddInputActionForKey(upAction);

	ButtonAction downAction;
	downAction.key = GameController::DownKey();
	downAction.action = [this](uint32_t dt, InputState state)
		{
			HandleGameControllerState(dt, state, PACMAN_MOVEMENT_DOWN);
		};
	controller.AddInputActionForKey(downAction);
}

void PacmanGame::Update(uint32_t dt)
{
	UpdatePacmanMovement();
	mPacman.Update(dt);

	mLevel.Update(dt);
}

void PacmanGame::Draw(Screen& screen)
{
	mLevel.Draw(screen);
	mPacman.Draw(screen);
}

const std::string& PacmanGame::GetName() const
{
	static std::string name = "!Pacman";
	return name;
}

void PacmanGame::ResetGame()
{
	mPressedDirection = PACMAN_MOVEMENT_NONE;
	mPacman.ResetScore();
}

void PacmanGame::UpdatePacmanMovement()
{
	if(mPressedDirection != PACMAN_MOVEMENT_NONE)
	{
		if(!mLevel.WillCollide(mPacman.GetBoundingBox(), mPressedDirection))
		{
			mPacman.SetMovementDirection(mPressedDirection);
		}
	}
}

void PacmanGame::HandleGameControllerState(uint32_t dt, InputState state, PacmanMovement direction)
{
	if(GameController::IsPressed(state))
	{
		mPressedDirection = direction;
	}
	else if(GameController::IsReleased(state) && mPressedDirection == direction)
	{
		mPressedDirection = PACMAN_MOVEMENT_NONE;
	}
}
