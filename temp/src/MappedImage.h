#pragma once

#include "ofMain.h"

const int rows = 11;
const int cols = 67;

class MappedImage {
	private:
		std::string images[rows][cols];
		ofImage image;
		float w, h;
		int x, y;
	public:
		void init();
		float getWidth() const;
		float getHeight() const;
		bool hasChanged();
		ofImage getImageFromMatrix(const ofVec2f& position);
};