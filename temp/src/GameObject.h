#pragma once

#include "ofMain.h"

class GameObject {
	public:
		virtual void init() = 0;
		virtual void update(float secs) = 0;
		virtual void draw() = 0;
		virtual bool isAlive() = 0;
		virtual ofBoxPrimitive bounds() = 0;
		virtual ofVec3f getPosition() const = 0;
};