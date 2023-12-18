/*
 * PacmanGameUtils.h
 *
 *  Created on: 18 de dez. de 2023
 *      Author: F46943A
 */

#ifndef GAMES_PACMAN_PACMANGAMEUTILS_H_
#define GAMES_PACMAN_PACMANGAMEUTILS_H_

#include "../../Utils/Vec2D.h"
#include <vector>

static const int PACMAN_MOVEMENT_SPEED = 50; //pixels per secont

enum PacmanMovement
{
	PACMAN_MOVEMENT_NONE = 0,
	PACMAN_MOVEMENT_UP,
	PACMAN_MOVEMENT_LEFT,
	PACMAN_MOVEMENT_DOWN,
	PACMAN_MOVEMENT_RIGHT
};

Vec2D GetMovementVector(PacmanMovement direction);
PacmanMovement GetOppositeDirection(PacmanMovement direction);
std::vector<PacmanMovement> GetPerpendicularMovements(PacmanMovement direction);

#endif /* GAMES_PACMAN_PACMANGAMEUTILS_H_ */
