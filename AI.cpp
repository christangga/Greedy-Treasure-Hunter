#include "AI.h"

AI::AI() {
	x = 0;
	y = 0;
}

AI::AI(float x, float y) {
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}

AI::~AI() {

}

void AI::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}

float AI::getPositionX() {
	return x;
}

float AI::getPositionY() {
	return y;
}

void AI::load(std::string filename) {
	texture.loadFromFile("images/" + filename);
	sprite.setTexture(texture);
}

void AI::draw(sf::RenderWindow& renderWindow) {
	renderWindow.draw(sprite);
}
