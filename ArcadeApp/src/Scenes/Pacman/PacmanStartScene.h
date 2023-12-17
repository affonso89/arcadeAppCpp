/*
 * PacmanStartScene.h
 *
 *  Created on: 17 de dez. de 2023
 *      Author: F46943A
 */

#ifndef SCENES_PACMAN_PACMANSTARTSCENE_H_
#define SCENES_PACMAN_PACMANSTARTSCENE_H_

#include "../ButtonOptionScene.h"

class PacmanStartScene: public ButtonOptionsScene
{
public:
	PacmanStartScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:

};

#endif /* SCENES_PACMAN_PACMANSTARTSCENE_H_ */
