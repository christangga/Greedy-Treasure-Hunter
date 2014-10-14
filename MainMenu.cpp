/* 	File 	: MainMenu.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window) {

	//Load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(texture);
	window.draw(sprite);

	//load gambar peti
	texture.loadFromFile("images/chest1.png");
	sf::Sprite sprite2(texture);
	sprite2.setPosition(400, 250);
	window.draw(sprite2);

	//load gambar orang
	texture.loadFromFile("images/hunter1.png");
	sf::Sprite sprite3(texture);
	sprite3.setPosition(270, 350);
	window.draw(sprite3);

	//load gambar kaki
	texture.loadFromFile("images/footprints1.png");
	sf::Sprite sprite4(texture);
	sprite4.setPosition(100, 250);
	window.draw(sprite4);
	sprite4.setPosition(160, 350);
	window.draw(sprite4);
	sprite4.setPosition(220, 430);
	window.draw(sprite4);

	//Play menu item coordinates
	MenuItem PlayButton;
	PlayButton.texture.loadFromFile("images/PlayButton.png");
	PlayButton.sprite.setTexture(PlayButton.texture);
	PlayButton.sprite.setPosition(840,325);
	PlayButton.action = Play;
	window.draw(PlayButton.sprite);

	//Credit menu item coordinates
	MenuItem CreditsButton;
	CreditsButton.texture.loadFromFile("images/CreditsButton.png");
	CreditsButton.sprite.setTexture(CreditsButton.texture);
	CreditsButton.sprite.setPosition(840,405);
	CreditsButton.action = Credits;
	window.draw(CreditsButton.sprite);

	//Exit menu item coordinates
	MenuItem ExitButton;
	ExitButton.texture.loadFromFile("images/ExitButton.png");
	ExitButton.sprite.setTexture(ExitButton.texture);
	ExitButton.sprite.setPosition(840,485);
	ExitButton.action = Exit;
	window.draw(ExitButton.sprite);
	window.display();

	_menuItems.push_back(PlayButton);
	_menuItems.push_back(CreditsButton);
	_menuItems.push_back(ExitButton);

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Sprite menuItemSprite = (*it).sprite;
		if (menuItemSprite.getPosition().y + 82 > y 
			&& menuItemSprite.getPosition().y < y 
			&& menuItemSprite.getPosition().x < x 
			&& menuItemSprite.getPosition().x + 150 > x) {
			return (*it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event menuEvent;

	while (42 != 43) {

		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
			
		}
	}
}

MainMenu::MenuResult MainMenu::ShowSub(sf::RenderWindow& window) {

	window.clear();
	//Load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/ChooseMode.png");
	sf::Sprite sprite(texture);
	window.draw(sprite);

	//tulisan OR
	texture.loadFromFile("images/OR.png");
	sf::Sprite sprite2 (texture);
	sprite2.setPosition(450, 350);
	window.draw(sprite2);

	//Setup clickable regions

	//Normal "Mode" menu item coordinates
	MenuItem NormalButton;
	NormalButton.texture.loadFromFile("images/normalpage.png");
	NormalButton.sprite.setTexture(NormalButton.texture);
	NormalButton.sprite.setPosition(100,200);
	NormalButton.action = NormalMode;
	window.draw(NormalButton.sprite);

	//Better menu item coordinates
	MenuItem BetterButton;
	BetterButton.texture.loadFromFile("images/expertpage.png");
	BetterButton.sprite.setTexture(BetterButton.texture);
	BetterButton.sprite.setPosition(600,200);
	BetterButton.action = BetterMode;
	window.draw(BetterButton.sprite);
	
	window.display();
	sf::Event event;
	while (true) {
		while(window.pollEvent (event))
		{
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.x < 400 && event.mouseButton.x > 100 && event.mouseButton.y < 600 && event.mouseButton.y > 200)
				{
					return MainMenu::GetChoosePlayer(window); //Normal
				}
				else
					return BetterMode;
			}
		}
	/*_menuItems.push_back(NormalButton);
	_menuItems.push_back(BetterButton);

	return GetMenuResponse(window);*/
	}
}

void MainMenu::ShowBeliBarang(sf::RenderWindow& window,int &modal, int &toolsmerah, int &toolskuning, int &toolshijau) {
	while (true) {
		window.clear();
		//Load menu image from file
		sf::Texture texture;
		texture.loadFromFile("images/MainMenu.png");
		sf::Sprite sprite(texture);
		window.draw(sprite);

		//gambar tools
		sf::Texture texture1;
		texture1.loadFromFile("images/toolsmerah.png");
		sf::Sprite sprite1(texture1);
		sprite1.setPosition(100, 330);
		window.draw(sprite1);

		texture1.loadFromFile("images/toolskuning.png");
		sprite1.setPosition(400, 330);
		window.draw(sprite1);

		texture1.loadFromFile("images/toolshijau.png");
		sprite1.setPosition(700, 330);
		window.draw(sprite1);

		//angka
		sf::Font font1;
		font1.loadFromFile("fonts/BACHELOR.TTF");
		sf::Text text1;
		text1.setFont(font1);
		text1.setColor(sf::Color::Black);
		text1.setCharacterSize(50);
		text1.setStyle(sf::Text::Bold);
		text1.setPosition(230, 360);
		string Tempstr = to_string(toolsmerah);
		text1.setString(Tempstr);
		window.draw(text1);

		//angka
		sf::Text text2;
		text2.setFont(font1);
		text2.setColor(sf::Color::Black);
		text2.setCharacterSize(50);
		text2.setStyle(sf::Text::Bold);
		text2.setPosition(530, 360);
		string Tempstr1 = to_string(toolskuning);
		text2.setString(Tempstr1);
		window.draw(text2);

		sf::Text text3;
		text3.setFont(font1);
		text3.setColor(sf::Color::Black);
		text3.setCharacterSize(50);
		text3.setStyle(sf::Text::Bold);
		text3.setPosition(830, 360);
		string Tempstr2 = to_string(toolshijau);
		text3.setString(Tempstr2);
		window.draw(text3);

		//modal
		texture.loadFromFile("images/Modal.png");
		sf::Sprite sprite3(texture);
		sprite3.setPosition(50, 550);
		window.draw(sprite3);

		sf::Text text4;
		text4.setFont(font1);
		text4.setColor(sf::Color::Red);
		text4.setCharacterSize(70);
		text4.setStyle(sf::Text::Bold);
		//text4.setStyle(sf::Text::Italic);
		text4.setPosition(350, 550);
		string Tempstr3 = to_string(modal);
		text4.setString(Tempstr3);
		window.draw(text4);

		//plus button
		MenuItem PlusButton;
		PlusButton.texture.loadFromFile("images/PlusButton.png");
		PlusButton.sprite.setTexture(PlusButton.texture);
		PlusButton.sprite.setPosition(200, 210);

		window.draw(PlusButton.sprite);
		PlusButton.sprite.setPosition(500, 210);
		window.draw(PlusButton.sprite);
		PlusButton.sprite.setPosition(800, 210);
		window.draw(PlusButton.sprite);


		//minus button
		MenuItem MinusButton;
		MinusButton.texture.loadFromFile("images/MinusButton.png");
		MinusButton.sprite.setTexture(MinusButton.texture);
		MinusButton.sprite.setPosition(200, 460);
		window.draw(MinusButton.sprite);
		MinusButton.sprite.setPosition(500, 460);
		window.draw(MinusButton.sprite);
		MinusButton.sprite.setPosition(800, 460);
		window.draw(MinusButton.sprite);

		//ready button
		texture.loadFromFile("images/Ready.png");
		sf::Sprite sprite2(texture);
		sprite2.setPosition(900, 580);
		window.draw(sprite2);


		//Setup clickable regions
		sf::Event event;
			while(window.pollEvent (event))
			{
				if(event.type == sf::Event::MouseButtonPressed)
				{
					if(event.mouseButton.x < 300 && event.mouseButton.x > 200 && event.mouseButton.y < 290 && event.mouseButton.y > 210 && modal>=3) {
						toolsmerah++;
						modal-=3;
					}
					if(event.mouseButton.x < 600 && event.mouseButton.x > 500 && event.mouseButton.y < 290 && event.mouseButton.y > 210 && modal>=2) {
						toolskuning++;
						modal-=2;
					}
					if(event.mouseButton.x < 900 && event.mouseButton.x > 800 && event.mouseButton.y < 290 && event.mouseButton.y > 210 && modal>=1) {
						toolshijau++;
						modal--;
					}
					if(event.mouseButton.x < 300 && event.mouseButton.x > 200 && event.mouseButton.y < 540 && event.mouseButton.y > 460) {
						if(toolsmerah>0) {
							toolsmerah--;
							modal+=3;
						}
					}
					if(event.mouseButton.x < 600 && event.mouseButton.x > 500 && event.mouseButton.y < 540 && event.mouseButton.y > 460) {
						if(toolskuning>0) {
							toolskuning--;
							modal+=2;
						}
					}
					if(event.mouseButton.x < 900 && event.mouseButton.x > 800 && event.mouseButton.y < 540 && event.mouseButton.y > 460) {
						if(toolshijau>0) {
							toolshijau--;
							modal++;
						}
					}
					if(event.mouseButton.x < 1000 && event.mouseButton.x > 900 && event.mouseButton.y <746 && event.mouseButton.y > 600) {
						return;
					}
				}
			}
		window.display();
	}
}

MainMenu::MenuResult  MainMenu::GetChoosePlayer(sf::RenderWindow& window)
{
		window.clear();
		sf::Texture texture;

		texture.loadFromFile("images/MainMenu.png");
		sf::Sprite sprite(texture);
		window.draw(sprite);

		texture.loadFromFile("images/dragoncopy.png");
		sf::Sprite sprite1(texture);
		sprite1.setPosition(100, 200);
		window.draw(sprite1);

		texture.loadFromFile("images/AIFire.png");
		sf::Sprite sprite2(texture);
		sprite2.setPosition(500, 250);
		window.draw(sprite2);
		
		texture.loadFromFile("images/HumanvsAI.png");
		sf::Sprite sprite4(texture);
		sprite4.setPosition(430, 450);
		window.draw(sprite4);
			
		window.display();
		//minta input user, waktu diklik nge return
		sf::Event event;
		while (true) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.mouseButton.x >= 500 && event.mouseButton.x <= 700 &&
						event.mouseButton.y >= 250 && event.mouseButton.y <= 350) {
							int greedytype = 1;
							return ChooseGreedy(window, greedytype);
					} else if (event.mouseButton.x >= 430 && event.mouseButton.x <= 780 &&
						event.mouseButton.y >= 450 && event.mouseButton.y <= 550) {
							int greedytype = 2;
							return ChooseGreedy(window, greedytype);
					}
				}
			}
		}
}

MainMenu::MenuResult  MainMenu::ChooseGreedy (sf::RenderWindow& window, int& greedytype) {
	window.clear();
	sf::Texture texture;

	texture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(texture);
	window.draw(sprite);

	texture.loadFromFile("images/GreedyByValue.png");
	sf::Sprite sprite2(texture);
	sprite2.setPosition(100, 300);
	window.draw(sprite2);

	texture.loadFromFile("images/GreedyByPath.png");
	sf::Sprite sprite3(texture);
	sprite3.setPosition(400, 300);
	window.draw(sprite3);
	window.display();

	//minta input user, waktu diklik nge return
		sf::Event event;
		while (true) {
			while (window.pollEvent(event)) {
				if (event.type == sf:: Event::MouseButtonPressed) {
					if (event.mouseButton.x >= 100 && event.mouseButton.x <= 300 &&
						event.mouseButton.y >= 300 && event.mouseButton.y <= 600 && greedytype == 1) {
							return AIonlyByValue;
					} else if (event.mouseButton.x >= 400 && event.mouseButton.x <= 600 &&
						event.mouseButton.y >= 300 && event.mouseButton.y <= 600 && greedytype == 1) {
							return AIonlyByDist;
					} else if (event.mouseButton.x >= 100 && event.mouseButton.x <= 300 &&
						event.mouseButton.y >= 300 && event.mouseButton.y <= 600 && greedytype == 2) {
							return VSAIByValue;
					} else if (event.mouseButton.x >= 400 && event.mouseButton.x <= 600 &&
						event.mouseButton.y >= 300 && event.mouseButton.y <= 600 && greedytype == 2) {
							return VSAIByDist;
					}
				}
			}
		}
}