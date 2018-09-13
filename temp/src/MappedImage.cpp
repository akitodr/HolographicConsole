#include "MappedImage.h"

void MappedImage::init() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			stringstream ss;
			ss << i + 1 << "/spaceship (" << j + 1 << ").png";
			images[i][j] = ss.str();
			cout << images[i][j] << endl;
			cout << "images[" << i << "][" << j << "]" << endl;
		}
	}

	w = ofGetWidth() / (float)cols;
	h = ofGetHeight() / (float)rows;
}

ofImage MappedImage::getImageFromMatrix(const ofVec2f& position) {
	x = position.x / w;
	y = position.y / h;

	image.load(images[y][cols - x]);

	cout << "[" << y << "]";
	cout << "[" << x << "]";
	cout<< "----> pos:" << position << endl;

	cout << images[y][cols - x] << endl;

	return image;
}

float MappedImage::getWidth() const {
	return image.getWidth();
}

float MappedImage::getHeight() const {
	return image.getHeight();
}

bool MappedImage::hasChanged() {
	return true;
}

