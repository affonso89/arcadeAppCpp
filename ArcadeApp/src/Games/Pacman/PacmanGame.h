/*
 * PacmanGame.h
 *
 *  Created on: 17 de dez. de 2023
 *      Author: F46943A
 */

#ifndef GAMES_PACMAN_PACMANGAME_H_
#define GAMES_PACMAN_PACMANGAME_H_

#include "../Game.h"
#include "PacmanLevel.h"
#include "Pacman.h"
#include "../../Graphics/SpriteSheet.h"
#include "../../Input/InputAction.h"

class PacmanGame : public Game
{
public:
	virtual void Init(GameController& controller) override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;
	virtual const std::string& GetName() const override;

private:
	void ResetGame();
	void UpdatePacmanMovement();
	void HandleGameControllerState(uint32_t dt, InputState state, PacmanMovement direction);
	void ResetLevel();

	PacmanMovement mPressedDirection;
	SpriteSheet mPacmanSpriteSheet;
	Pacman mPacman;
	PacmanLevel mLevel;
};

#endif /* GAMES_PACMAN_PACMANGAME_H_ */
