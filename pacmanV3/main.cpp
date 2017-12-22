#include "stdafx.h"
#include "MainMenu.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include <sstream>
#include "Utils.h"
#include <cmath> //для возведения в степень
using namespace sf;
using namespace std;

bool checkCollisionWithGhost(Player player, Enemy enemy)
{
	if (player.sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
		return true;
	return false;
}

/*
	Код грязный, в будущем почищу и оптимизирую
	Многие моменты можно было реализовать иначе и возможно проще, но не хватило времени

*/

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
	Clock eatableClock;

	//Создаем переменную текущего кадра
	float CurrentFrame=0;
	float ghostCurrentFrame = 0;
	float eatableTime=0.0;

	//Создадим персонажей
	Enemy ghost1("enemy1.png", 13 * TILE_SCALE*TILE_SIZE, 5 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost2("enemy2.png", 1 * TILE_SCALE*TILE_SIZE, 1 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost3("enemy3.png", 19 * TILE_SCALE*TILE_SIZE, 1 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Enemy ghost4("enemy4.png", 10 * TILE_SCALE*TILE_SIZE, 5 * TILE_SCALE*TILE_SIZE, 16.0, 16.0);
	Player PacPlayer("hero.png",10 * TILE_SCALE*TILE_SIZE,20 *TILE_SCALE*TILE_SIZE,14.5,14.5);

	//Спрайт карты
	Image map_image;
	map_image.loadFromFile("images/MTS16.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	//Спрайт жизней
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

	int deadGhostCount = 0;
	
	
	//Основной рабочий цикл
	while (window.isOpen())
	{
		
		//Обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();		
		}

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 600; //Скорость игры

			
			//Движение игрока
			PacPlayer.update(CurrentFrame, time,eatableClock);
			ghost1.update(ghostCurrentFrame, time);
			ghost2.update(ghostCurrentFrame, time);
			ghost3.update(ghostCurrentFrame, time);
			ghost4.update(ghostCurrentFrame, time);
			window.clear();

			//Отрисовка карты
			drawMap(window, s_map);

			//Задаем боковую панель
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

			//Отрисовка элементов интерфейся

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
			if (isEatable) {
				eatableTime = eatableClock.getElapsedTime().asSeconds();
				if (eatableTime >= 7)
				{
					isEatable = false;
					eatableClock.restart();
				}
			}
			//Съедаем призраков, если работает бонус
			if(checkCollisionWithGhost(PacPlayer, ghost1)&&isEatable)
			{
				ghost1.speed = ghost1.dx= ghost1.dy =0;
				ghost1.x = 10 * TILE_SCALE*TILE_SIZE;
				ghost1.y = 12 * TILE_SCALE*TILE_SIZE;
				deadGhostCount ++;	
				PacPlayer.score += pow(deadGhostCount*10, 2);
			}
			if (checkCollisionWithGhost(PacPlayer, ghost2) && isEatable)
			{
				ghost2.speed = ghost2.dx = ghost2.dy = 0;
				ghost2.x = 9 * TILE_SCALE*TILE_SIZE;
				ghost2.y = 12 * TILE_SCALE*TILE_SIZE;
				deadGhostCount ++;
				PacPlayer.score += pow(deadGhostCount*10, 2);
			}
			if (checkCollisionWithGhost(PacPlayer, ghost3) && isEatable)
			{
				ghost3.speed = ghost3.dx = ghost3.dy = 0;
				ghost3.x = 11 * TILE_SCALE*TILE_SIZE;
				ghost3.y = 12 * TILE_SCALE*TILE_SIZE;
				deadGhostCount ++;
				PacPlayer.score += pow(deadGhostCount*10, 2);
			}
			if (checkCollisionWithGhost(PacPlayer, ghost4) && isEatable)
			{
				ghost4.speed = ghost4.dx = ghost4.dy = 0;
				ghost4.x = 11 * TILE_SCALE*TILE_SIZE;
				ghost4.y = 12 * TILE_SCALE*TILE_SIZE;
				deadGhostCount++;
				PacPlayer.score += pow(deadGhostCount*10, 2);
			}
			//ПОБЕДА
			if (playerCookieScoreString.str() == "0") 
			{
				gameWinner(window, PacPlayer.score);
			}

			//ПОРАЖЕНИЕ
			if ((checkCollisionWithGhost(PacPlayer, ghost1) || checkCollisionWithGhost(PacPlayer, ghost2) || checkCollisionWithGhost(PacPlayer, ghost3) || checkCollisionWithGhost(PacPlayer, ghost4)) && !isEatable) 
			{
				PacPlayer.lives -= 1;
				if (PacPlayer.lives < 0)
				{
					gameLoser(window,PacPlayer.score);
				}

			}
		
		
	}
	return 0;
}