/*
 * GameScene.h
 *
 *  Created on: 22 de jul. de 2023
 *      Author: affon
 */

#ifndef SCENES_GAMESCENE_H_
#define SCENES_GAMESCENE_H_

#include "Scene.h"
#include "../Games/Game.h"
#include <memory>

class GameScene: public Scene
{
public:
	GameScene(std::unique_ptr<Game> optrGame);
	virtual ~GameScene() {}
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;

	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Game> mGame;
};

#endif /* SCENES_GAMESCENE_H_ */
