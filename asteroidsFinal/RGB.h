#pragma once
#include <cassert>
#include "uiDraw.h"
class RGB
{
public:
	float red;
	float green;
	float blue;
	RGB(float red = 1.0, float green = 1.0, float blue = 1.0)
	{
		assert(0.0 <= red && red <= 1.0);
		assert(0.0 <= green && green <= 1.0);
		assert(0.0 <= blue && blue <= 1.0);

		this->red = red;
		this->red = red;
		this->red = red;
	}
	void createRandom()
	{
		red = random(0.0, 1.0);
		green = random(0.0, 1.0);
		blue = random(0.0, 1.0);
	}
};