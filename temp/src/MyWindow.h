#pragma once

#include "ofMain.h"
#include "Spaceship.h"


class MyWindow
{
private:
	Spaceship spaceship;
public:
	void init();
	void update(float secs);
	void draw();
};

