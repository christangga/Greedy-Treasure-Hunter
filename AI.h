#pragma once
#include "stdafx.h"

class AI {
public:
	AI();
	AI(float x, float y);
	~AI();

	void setPosition(float x, float y);
	float getPositionX();
	float getPositionY();

	void load(std::string filename);
	void draw(sf::RenderWindow& renderWindow);

private:
	float x, y;
	sf::Sprite sprite;
	sf::Texture texture;
};
