/* 	File 	: Game.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#ifndef _GAME_H
#define _GAME_H
#include "stdafx.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "hunter.h"
#include "peti.h"

class Game {
public:
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();
	static void ShowSubMenu();
	static void ShowMenuPlayer();
	static void GetChoosePlayer();
	static void ChooseGreedy();

	enum GameState {
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, ShowCredits, Exiting, SubMenuNormal, AIPlayByValue, AIPlayByDist, HumanPlayByValue, HumanPlayByDist, AIPlayBetter
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

public:
	static void Start(int &modal, int &greedy_code, int &x0, int &x2, int &x4, int &mode_n, int &ModeManusia);
};

#endif