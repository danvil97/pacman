#include "stdafx.h"
#include "MainMenu.h"
#include "Player.h"
#include "Enemy.h"
#include <sstream>
#include "Utils.h"
using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS" );
	
	int GameState = MENU;
	int xPosTile;
	int yPosTile;
	//Создание окна
	RenderWindow window(VideoMode(600, 650), "Pac-Man");
	window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(true);
	MainMenuW(window,GameState);

	//Создаем время SFML
	Clock clock;
	Clock EatableClock;
	//Создаем переменную текущего кадра
	float CurrentFrame=0;
	float eatableTime=0.0;

	//Создадим персонажа
	Enemy ghost1("enemy1.png", 13 * TILE_SCALE*TILE_SIZE, 5 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost2("enemy1.png", 1 * TILE_SCALE*TILE_SIZE, 1 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost3("enemy1.png", 19 * TILE_SCALE*TILE_SIZE, 1 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost4("enemy1.png", 10 * TILE_SCALE*TILE_SIZE, 5 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Player PacPlayer("hero.png",10*TILE_SCALE*TILE_SIZE,20*TILE_SCALE*TILE_SIZE,16.0,16.0);
	//Отрисовка карты
	Image map_image;
	map_image.loadFromFile("images/MTS16.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	//Жизни
	Image lives_image;
	lives_image.loadFromFile("images/lives.png");
	Texture lives;
	lives.loadFromImage(lives_image);
	Sprite s_lives;
	s_lives.setTexture(lives);

	//Создание текста
	Font font;
	font.loadFromFile("fonts/PixFont.otf");
	Text PlayerScore("",font,28);
	PlayerScore.setColor(Color::White);
	Text PlayerPos("", font, 28);
	PlayerScore.setColor(Color::White);

	bool isPause = false;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (GameState) {
		case MENU:MainMenuW(window,GameState);
		case PAUSE:while (GameState!=PLAY) {
			if (Keyboard::isKeyPressed(Keyboard::Return))
				GameState = PLAY;
		}
		}
		if (PacPlayer.lives >= 0) {
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 600; //Скорость игры
			//cout << time << "\n";
			

			//Движение игрока
			PacPlayer.update(CurrentFrame, time);
			ghost1.update(CurrentFrame, time);
			ghost2.update(CurrentFrame, time);
			ghost3.update(CurrentFrame, time);
			ghost4.update(CurrentFrame, time);
			window.clear();

			//Отрисовка карты
			drawMap(window, s_map);
			//Счет

			//Отрисовка счета


			ostringstream playerScoreString;
			playerScoreString << PacPlayer.score;
			ostringstream playerCookieScoreString;
			playerCookieScoreString << TOLTAL_COOKIE_COUNT - PacPlayer.CookieCount;
			PlayerScore.setString("SCORE\n" + playerScoreString.str() + "\nLIVES\n" + "\nCOOKIES\n" + playerCookieScoreString.str());

			s_lives.setTextureRect(IntRect(0, 0, 16 * PacPlayer.lives, 16));
			s_lives.setPosition(500, 100);
			s_lives.setScale(1.6, 1.6);

			xPosTile = (PacPlayer.x / (TILE_SCALE*TILE_SIZE));
			yPosTile = (PacPlayer.y / (TILE_SCALE*TILE_SIZE));
			ostringstream playerPosStringX;
			playerPosStringX << xPosTile;
			ostringstream playerPosStringY;
			playerPosStringY << yPosTile;
			PlayerPos.setString("CurPos:\nx:" + playerPosStringX.str() + "\ny:" + playerPosStringY.str());

			PlayerScore.setPosition(500, 0);
			PlayerPos.setPosition(500, 200);
			window.draw(PlayerScore);
			window.draw(PlayerPos);
			window.draw(s_lives);
			window.draw(ghost1.sprite);
			window.draw(ghost2.sprite);
			window.draw(ghost3.sprite);
			window.draw(ghost4.sprite);
			window.draw(PacPlayer.sprite);

			window.display();
			//clock.restart();
			if (playerCookieScoreString.str() == "0")	window.close();
			if ((PacPlayer.sprite.getGlobalBounds().intersects(ghost1.sprite.getGlobalBounds())|| PacPlayer.sprite.getGlobalBounds().intersects(ghost2.sprite.getGlobalBounds())|| PacPlayer.sprite.getGlobalBounds().intersects(ghost3.sprite.getGlobalBounds())|| PacPlayer.sprite.getGlobalBounds().intersects(ghost4.sprite.getGlobalBounds()))&&!isEatable) {
				PacPlayer.lives -= 1;
				PacPlayer.speed = 0; ghost1.speed = 0;
				PacPlayer.sprite.setPosition(1 * TILE_SCALE*TILE_SIZE, 1 * TILE_SCALE*TILE_SIZE);
				ghost1.sprite.setPosition(5 * TILE_SCALE*TILE_SIZE, 5 * TILE_SCALE*TILE_SIZE);
				gameRestart(window,GameState);
			}
			if ((PacPlayer.sprite.getGlobalBounds().intersects(ghost1.sprite.getGlobalBounds()) || PacPlayer.sprite.getGlobalBounds().intersects(ghost2.sprite.getGlobalBounds()) || PacPlayer.sprite.getGlobalBounds().intersects(ghost3.sprite.getGlobalBounds()) || PacPlayer.sprite.getGlobalBounds().intersects(ghost4.sprite.getGlobalBounds())) && !isEatable){
			}
		}
		else
		{
			gameLoser(window,GameState,PacPlayer.score);
		}
		
	}
	return 0;
}