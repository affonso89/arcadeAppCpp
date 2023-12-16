/*
 * NotImplementedScene.h
 *
 *  Created on: 16 de dez. de 2023
 *      Author: F46943A
 */

#ifndef APP_NOTIMPLEMENTEDSCENE_H_
#define APP_NOTIMPLEMENTEDSCENE_H_

#include "Scene.h"

class Screen;

class NotImplementedScene: public Scene
{
public:
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;
};

#endif /* APP_NOTIMPLEMENTEDSCENE_H_ */
