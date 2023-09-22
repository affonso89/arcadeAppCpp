/*
 * Button.h
 *
 *  Created on: 22 de set. de 2023
 *      Author: affon
 */

#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include <string>
#include "../Shapes/AARectangle.h"
#include <functional>
#include "../Graphics/Color.h"

#include "../Graphics/BitmapFont.h"

class Screen;

class Button
{
public:
	using ButtonAction = std::function<void(void)>;

	Button(const BitmapFont& bitmapFont, const Color& textColor, const Color& highlightColor = Color::White());
	void Init(Vec2D topLeft, unsigned int width, unsigned int height);
	void Draw(Screen& theScreen);
	void ExecuteAction();

	inline void SetButtonText(const std::string& text) {mTitle = text;}
	inline const std::string& GetButtonText() const {return mTitle;}
	inline void SetHighlighted(bool highlighted) {mHighlighted = highlighted;}
	inline bool IsHighlighted() const {return mHighlighted;}
	inline void SetButtonAction(Button::ButtonAction action) {mAction = action;}

private:
	const BitmapFont& mBitmapFont;
	std::string mTitle;
	AARectangle mBBox;

	bool mHighlighted;
	ButtonAction mAction;
	Color mHighlightColor;
	Color mTextColor;
};


#endif /* APP_BUTTON_H_ */
