/*
 * ArcadeScene.cpp
 *
 *  Created on: 18 de jul. de 2023
 *      Author: affon
 */

#include "ArcadeScene.h"
#include "../Graphics/Screen.h"
#include "../Shapes/Line2D.h"
#include "../Shapes/AARectangle.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Circle.h"
#include "../Graphics/Color.h"
#include "../Input/GameController.h"
#include <iostream>
#include "../App/App.h"

ArcadeScene::ArcadeScene()
{

}
void ArcadeScene::Init()
{
	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [](uint32_t dt, InputState state)
	{
		if(GameController::IsPressed(state))
				std::cout << "Action button was pressed!" << std::endl;
	};

	mGameController.AddInputAtionForKey(action);

	MouseButtonAction mouseAction;
	mouseAction.mouseButton = GameController::LeftMouseButton();
	mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
	{
		if(GameController::IsPressed(state))
		{
			std::cout << "Left mouse button pressed!" << std::endl;
		}
	};

	mGameController.AddMouseButtonAction(mouseAction);

	mGameController.SetMouseMovedAction([](const MousePosition& mousePosition){
		std::cout << "Mouse position x: " << mousePosition.xPos << ", y: " << mousePosition.yPos << std::endl;
	});
}
void ArcadeScene::Update(uint32_t dt)
{

}
void ArcadeScene::Draw(Screen& theScreen)
{
	const BitmapFont& font = App::Singleton().GetFont();

	AARectangle rect = {Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()};

	Vec2D textDrawPosition;

	textDrawPosition = font.GetDrawPosition(GetSceneName(), rect, BFXA_CENTER, BFYA_CENTER);

	theScreen.Draw(font, GetSceneName(), textDrawPosition, Color::Red());
}
const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade Scene";
	return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetSCene(eGame game)
{
	switch(game)
	{
		case TETRIS:
		{

		}
		break;

		case BREAK_OUT:
		{

		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{

		}
		break;

		case NUM_GAMES:
		{

		}
		break;
		default:
		{

		}
		break;
	}

	return nullptr;
}
