/*
 * PacmanLevel.h
 *
 *  Created on: 18 de dez. de 2023
 *      Author: F46943A
 */

#ifndef GAMES_PACMAN_PACMANLEVEL_H_
#define GAMES_PACMAN_PACMANLEVEL_H_

#include "../../Utils/Vec2D.h"
#include "../BreakOut/Excluder.h"
#include <string>
#include <vector>
#include "PacmanGameUtils.h"

class Screen;
class Pacman;

class PacmanLevel
{
public:
	bool Init(const std::string& levelPath, Pacman* noptrPacman);
	void Update(uint32_t dt);
	void Draw(Screen& screen);

	bool WillCollide(const AARectangle& aBBox, PacmanMovement direction) const;
	void ResetLevel();

	inline Vec2D GetLayoutOffset() const {return mLayoutOffset;}
	inline Vec2D GetPacmanSpawnLocation() const {return mPacmanSpawnLocation;}
	bool IsLevelOver() const;
	void IncreaseLevel();
	void ResetToFirstLevel();

private:
	struct Tile
	{
		Vec2D position = Vec2D::Zero;
		Vec2D offset = Vec2D::Zero;
		int width = 0;
		int collidable = 0;
		int isTeleportTile = 0;
		int excludePelletTile = 0;
		int pacmanSpawnPoint = 0;
		char teleportToSymbol = 0;
		char symbol = '-';
	};

	struct Pellet
	{
		uint32_t score = 0;
		AARectangle mBBox;
		int powerPellet = 0;
		int eaten = 0;
	};

	bool LoadLevel(const std::string& levelPath);
	Tile* GetTileForSymbol(char symbol);
	void ResetPellets();
	bool HasEatenAllPellets() const;
	size_t NumPelletsEaten() const;

	std::vector<Excluder> mWalls;
	std::vector<Tile> mTiles;

	std::vector<Tile> mExclusionTiles;
	std::vector<Pellet> mPellets;
	Vec2D mPacmanSpawnLocation;
	Vec2D mLayoutOffset;
	size_t mTileHeight;
	int mCurrentLevel;
	Pacman* mnoptrPacman;
};

#endif /* GAMES_PACMAN_PACMANLEVEL_H_ */
