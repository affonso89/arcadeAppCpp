/*
 * Game.h
 *
 *  Created on: 22 de jul. de 2023
 *      Author: affon
 */

#ifndef GAMES_GAME_H_
#define GAMES_GAME_H_

#include <string>
#include <stdint.h>

class GameController;
class Screen;

class Game
{
public:
	virtual ~Game(){}
	virtual void Init(GameController& controller) = 0;
	virtual void Update(uint32_t dt) = 0;
	virtual void Draw(Screen& screen) = 0;
	virtual std::string GetName() const = 0;
};

#endif /* GAMES_GAME_H_ */
