/* 	File 	: Game.cpp 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#include "Game.h"

void Game::Start(int &modal, int &greedy_code, int &hx0, int &hx2, int &hx4, int &mode_n, int &ModeManusia) {
	if (_gameState != Uninitialized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(1024, 640, 32), "Forget-Us-Not");
	_gameState = Game::ShowingSplash;

	while (true) {
		GameLoop();
		if (_gameState == HumanPlayByDist) {
			MainMenu::ShowBeliBarang(_mainWindow, modal,hx0,hx2,hx4);
			mode_n = 1;
			greedy_code = 2;
			ModeManusia=2;
			break;
		} else if (_gameState == HumanPlayByValue) {
			MainMenu::ShowBeliBarang(_mainWindow, modal,hx0,hx2,hx4);
			mode_n = 1;
			greedy_code = 1;
			ModeManusia=2;
			break;
		} else if (_gameState == AIPlayByValue) {
			mode_n=1; //mode normal
			greedy_code = 1;
			ModeManusia = 1;
			break;
		} else if (_gameState == AIPlayByDist) {
			mode_n=1; //mode normal
			greedy_code = 2;
			ModeManusia = 1;
			break;
		} else if (_gameState == AIPlayBetter) {
			mode_n=2; //mode better
			break;
		}
	}
	_mainWindow.close();
}

void Game::GameLoop() {
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent)) {
		switch(_gameState) {
		case Game::ShowingSplash:
			ShowSplashScreen();
			break;
		case Game::ShowingMenu:
			ShowMenu();
			break;
		case Game::Playing:
			ShowSubMenu();
			break;
		case Game::AIPlayByValue:
			break;
		case Game::AIPlayBetter:
			break;
		case Game::HumanPlayByValue:
			break;
		case Game::HumanPlayByDist:
			break;
		case Game::Exiting:
			_mainWindow.close();
			break;
		case Game::ShowCredits:
			sf::Texture texture;
			texture.loadFromFile("images/Credits.png");
			texture.setSmooth(true);
			sf::Sprite sprite;
			sprite.setTexture(texture);
			_mainWindow.draw(sprite);
			_mainWindow.display();
			if (currentEvent.type == sf::Event::KeyPressed) {
				if (currentEvent.key.code == sf::Keyboard::Escape) {
					ShowMenu();
				}
			}
			break;
		
		}
	}
}

void Game::ShowSplashScreen() {
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result) {
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	case MainMenu::Credits :
		_gameState = Game::ShowCredits;
		break;
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	}
}

void Game::ShowSubMenu()
{
	MainMenu SubMenu;
	MainMenu::MenuResult result = SubMenu.ShowSub(_mainWindow);
	switch (result) {
	case MainMenu::BetterMode:
		_gameState = Game::AIPlayBetter; //beter mode ai only
		break;
	case MainMenu::VSAIByValue:
		_gameState = Game::HumanPlayByValue; //normal mode human vs ai
		break;
	case MainMenu::VSAIByDist:
		_gameState = Game::HumanPlayByDist; //normal mode human vs ai
		break;
	case MainMenu::AIonlyByValue:
		_gameState = Game::AIPlayByValue; //normal mode ai only
		break;
	case MainMenu::AIonlyByDist:
		_gameState = Game::AIPlayByDist; //normal mode ai only
		break;
	}
}

void Game::ShowMenuPlayer() {
	MainMenu MenuPlayer;
	MainMenu::MenuResult result = MenuPlayer.GetChoosePlayer(_mainWindow);
}

void Game::GetChoosePlayer(){
	MainMenu ChoosePlayer;
	MainMenu::MenuResult result = ChoosePlayer.GetChoosePlayer(_mainWindow);

}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
