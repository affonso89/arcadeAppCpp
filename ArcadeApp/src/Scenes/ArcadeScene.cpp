/*
 * ArcadeScene.cpp
 *
 *  Created on: 18 de jul. de 2023
 *      Author: affon
 */

#include "ArcadeScene.h"
#include "../Graphics/Screen.h"
#include "../Input/GameController.h"
#include <iostream>
#include "../App/App.h"
#include "GameScene.h"
#include "../Games/BreakOut/BreakOut.h"
#include "NotImplementedScene.h"

ArcadeScene::ArcadeScene():ButtonOptionsScene({"Tetris", "Break Out!", "Asteroids", "!Pac-man"}, Color::Cyan())
{

}
void ArcadeScene::Init()
{
	std::vector<Button::ButtonAction> actions;

	actions.push_back([this]{
			App::Singleton().PushScene(GetSCene(TETRIS));
		});

	actions.push_back([this]{
			App::Singleton().PushScene(GetSCene(BREAK_OUT));
		});

	actions.push_back([this]{
			App::Singleton().PushScene(GetSCene(ASTEROIDS));
		});

	actions.push_back([this]{
			App::Singleton().PushScene(GetSCene(PACMAN));
		});

	SetButtonActions(actions);

	ButtonOptionsScene::Init();

	//temp
	{
		mAnimationPlayer.Init(App::Singleton().GetBasePath() + "Assets/Pacman_animations.txt");
		mSpriteSheet.Load("PacmanSprites");
		mAnimationPlayer.Play("move_left", true);
	}
}
void ArcadeScene::Update(uint32_t dt)
{
	mAnimationPlayer.Update(dt);
}
void ArcadeScene::Draw(Screen& theScreen)
{
	ButtonOptionsScene::Draw(theScreen);

//	AnimationFrame frame = mAnimationPlayer.GetCurrentAnimationFrame();
//
//	Color frameColor = frame.frameColor;
//
//	theScreen.Draw(mSpriteSheet, frame.frame, frame.offset, frameColor);
}
const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade";
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
			std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();

			std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));

			return breakoutScene;
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
	}

	std::unique_ptr<Scene> notImplementedScene = std::make_unique<NotImplementedScene>();

	return notImplementedScene;
}
