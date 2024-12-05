#pragma once
#include "Button.h"
class RestartButton : public Button
{
	// Button을(를) 통해 상속됨
	void ClickEvent() override;
};

