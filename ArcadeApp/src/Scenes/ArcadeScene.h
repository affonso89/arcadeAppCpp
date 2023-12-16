/*
 * ArcadeScene.h
 *
 *  Created on: 18 de jul. de 2023
 *      Author: affon
 */

#ifndef SCENES_ARCADESCENE_H_
#define SCENES_ARCADESCENE_H_

#include "ButtonOptionScene.h"
#include "../Graphics/AnimationPlayer.h"
#include <memory>

enum eGame
{
	TETRIS = 0,
	BREAK_OUT,
	ASTEROIDS,
	PACMAN,
	NUM_GAMES
};

class Screen;

class ArcadeScene: public ButtonOptionsScene
{
public:
	ArcadeScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Scene> GetSCene(eGame game);

	//temp
	AnimationPlayer mAnimationPlayer;
	SpriteSheet mSpriteSheet;
};



#endif /* SCENES_ARCADESCENE_H_ */
