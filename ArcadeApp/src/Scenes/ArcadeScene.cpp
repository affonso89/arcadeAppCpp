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

ArcadeScene::ArcadeScene()
{

}
void ArcadeScene::Init()
{

}
void ArcadeScene::Update(uint32_t dt)
{

}
void ArcadeScene::Draw(Screen& theScreen)
{
	//Line2D line = {Vec2D(0, 0), Vec2D(theSCreen.Width(), theScreen.Height())};
	Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
	AARectangle rect = {Vec2D(theScreen.Width() / 2 - 25, theScreen.Height() / 2 - 25), 50, 50};
	Circle circle = {Vec2D(theScreen.Width() / 2 + 50, theScreen.Height() / 2 + 50), 50};

	theScreen.Draw(triangle, Color::Red(), true, Color::Red());
	theScreen.Draw(rect, Color::Blue(), true, Color::Blue());
	theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
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
