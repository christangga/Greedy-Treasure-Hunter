/* 	File 	: SplashScreen.cpp
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#include "SplashScreen.h"

void (SplashScreen::Show(sf::RenderWindow &renderWindow)) {
	sf::Texture texture;
	if (!texture.loadFromFile("images/SplashScreen.png")) {
		return;
	}
	sf::Sprite sprite(texture);
	sprite.setPosition(243, 20);
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed) {
				return;
			}
		}
	}
}
