/* 	File 	: MainMenu.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#include "stdafx.h"

class MainMenu {
public:
	enum MenuResult { Nothing, Play, Credits, Exit, NormalMode, BetterMode, VSAIByValue, VSAIByDist, AIonlyByValue, AIonlyByDist, Startgame};	
	
	struct MenuItem
		{
		public:
			sf::Texture texture;
			sf::Sprite sprite;
			MenuResult action;
		};
	
	MenuResult Show(sf::RenderWindow& renderWindow);
	MenuResult ShowSub(sf::RenderWindow& renderWindow);
	static void ShowBeliBarang(sf::RenderWindow& renderWindow,int& modal, int &toolsmerah, int &toolskuning, int &toolshijau);
	MenuResult GetChoosePlayer(sf::RenderWindow& renderWindow);
	MenuResult ChooseGreedy(sf::RenderWindow& renderWindow, int& greedytype);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;

};
