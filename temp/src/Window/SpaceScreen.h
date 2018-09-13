#pragma once

#include "ofMain.h"
#include "../Star.h"

class SpaceScreen {
	private:
		vector<Star*> stars;
		float radius = 1.0f;
	public:
		void init();
		void update(float secs);
		void draw();
};