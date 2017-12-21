#pragma once
#include "stdafx.h"
#include "Utils.h"
	using namespace sf;
	void gameLoser(RenderWindow & window, int &GameState,int score) 
	{
		Texture imgBG;
		imgBG.loadFromFile("images/lose.png");
		Sprite sprBG;
		sprBG.setTexture(imgBG);
		sprBG.setPosition(0, 0);

		Font font;
		font.loadFromFile("fonts/PixFont.otf");
		Text texts(std::to_string(score) , font, 40);
		texts.setColor(Color::White);
		texts.setPosition(250, 310);
		bool isMenu = 1;
		window.clear();
		window.draw(sprBG);
		window.draw(texts);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Return))
			window.close();
	}
	void gameRestart(RenderWindow & window, int &GameState) 
	{
	}
	void MainMenuW(RenderWindow & window,int &GameState) 
	{
		Texture menuBackground, menuButton1, menuButton2, menuButton3;
		menuBackground.loadFromFile("images/menu/MainMenu.png");
		menuButton1.loadFromFile("images/menu/Start.png");
		menuButton2.loadFromFile("images/menu/Options.png");
		menuButton3.loadFromFile("images/menu/Exit.png");
		Sprite menuB1(menuButton1), menuB2(menuButton2), menuB3(menuButton3), menuBg(menuBackground);
		bool isMenu = 1;
		int menuNum = 0;
		menuB1.setPosition(159,381);
		menuB2.setPosition(208,440);
		menuB3.setPosition(240,495);
		menuBg.setPosition(0,0);

		while (isMenu)
		{
			if (IntRect(159, 381, 295, 59).contains(Mouse::getPosition(window)))  menuNum = 1; 
			if (IntRect(208, 440, 191, 55).contains(Mouse::getPosition(window))) menuNum = 2; 
			if (IntRect(240, 495,121, 52).contains(Mouse::getPosition(window)))  menuNum = 3; 

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { isMenu = false; GameState = PLAY; }
				//if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
				if (menuNum == 3) { window.close(); isMenu = false; }

			}

			window.draw(menuBg);
			window.draw(menuB1);
			window.draw(menuB2);
			window.draw(menuB3);

			window.display();
		}
		}