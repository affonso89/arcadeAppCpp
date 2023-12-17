/*
 * PacmanGame.h
 *
 *  Created on: 17 de dez. de 2023
 *      Author: F46943A
 */

#ifndef GAMES_PACMAN_PACMANGAME_H_
#define GAMES_PACMAN_PACMANGAME_H_

#include "../Game.h"

class PacmanGame : public Game
{
public:
	virtual void Init(GameController& controller) override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;
	virtual const std::string& GetName() const override;
};

#endif /* GAMES_PACMAN_PACMANGAME_H_ */
