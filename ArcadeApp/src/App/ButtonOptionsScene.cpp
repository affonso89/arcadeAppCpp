/*
 * ButtonOptionsScene.cpp
 *
 *  Created on: 24 de out. de 2023
 *      Author: affon
 */

#include "ButtonOptionScene.h"
#include "App.h"
#include "../Graphics/BitmapFont.h"
#include "../Utils/Utils.h"

ButtonOptionsScene::ButtonOptionsScene(const std::vector<std::string>& optionNames, const Color& textColor) :
	mHighlightedOption(0)
{
	const BitmapFont & font = App::Singleton().GetFont();

	for(size_t i = 0; optionNames.size(); ++1)
	{
		mButtons.push_back(Button(font, textColor));
		mButtons.back().SetButtonText(optionNames[i]);
	}

	if(optionNames.size() > 0)
	{
		mButtons[mHighlightedOption].SetHighlighted(true);
	}
}

void ButtonOptionsScene::Init()
{

}

void ButtonOptionsScene::Update(uint32_t dt)
{

}

void ButtonOptionsScene::Draw(Screen& theScreen)
{
	//here
}

void ButtonOptionsScene::SetButtonActions(const std::vector<Button::ButtonAction>& buttonActions)
{
	for(size_t i = 0; i < mButtons.size(); ++i)
	{
		mButtons[i].SetButtonAction(buttonActions[i]);
	}
}

void ButtonOptionsScene::SetNextButtonHighlighted()
{
	mHighlightedOption = (mHighlightedOption + 1)% mButtons.size();

	HighlighCurrentButton();
}

void ButtonOptionsScene::SetPreviousButtonHighlighted()
{
	--mHighlightedOption;

	if(mHighlightedOption < 0)
	{
		mHighlightedOption = static_cast<int>(mButtons.size()) - 1;
	}

	HighlighCurrentButton();
}

void ButtonOptionsScene::ExecuteCurrentButtonAction()
{
	mButtons[mHighlightedOption].ExecuteAction();
}

void ButtonOptionsScene::HighlighCurrentButton()
{
	for(auto& button : mButtons)
	{
		button.SetHighlighted(false);
	}

	mButtons[mHighlightedOption].SetHighlighted(true);
}
