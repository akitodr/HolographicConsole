#pragma once

#include "ofMain.h"
#include "../Spaceship.h"


class ShipScreen
{
private:
	Spaceship spaceship;
	float w, h;
public:
	void draw();
};

