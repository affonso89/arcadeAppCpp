/*
 * ButtonOptionScene.h
 *
 *  Created on: 24 de out. de 2023
 *      Author: affon
 */

#ifndef APP_BUTTONOPTIONSCENE_H_
#define APP_BUTTONOPTIONSCENE_H_

#include "../Scenes/Scene.h"
#include "../App/Button.h"
#include <string>
#include <vector>

class Screen;

class ButtonOptionsScene: public Scene
{
public:

	ButtonOptionsScene(const std::vector<std::string>& optionNames, const Color& textColor);

	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;

	void SetButtonActions(const std::vector<Button::ButtonAction>& buttonActions);

private:

	void SetNextButtonHighlighted();
	void SetPreviousButtonHighlighted();
	void ExecuteCurrentButtonAction();
	void HighlighCurrentButton();

	std::vector<Button> mButtons;
	int mHighlightedOption;
};

#endif /* APP_BUTTONOPTIONSCENE_H_ */
