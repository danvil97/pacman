#include "Player.h"
#include "stdafx.h"
using namespace sf;

void Player::mapInteraction(float time)
{
	for (int i = (y) / (TILE_SCALE*TILE_SIZE); i < (y + h*PLAYER_SCALE) / (TILE_SCALE*TILE_SIZE); i++)
		for (int j = (x) / (TILE_SCALE*TILE_SIZE); j < (x + w*PLAYER_SCALE) / (TILE_SCALE*TILE_SIZE); j++)
		{
			if (TileMap[i][j] == 'j')
			{
				score += 10;
				CookieCount += 1;
				TileMap[i][j] = '0';
			}
			if (TileMap[i][j] == 'l')
			{
				x = 17 * TILE_SCALE*TILE_SIZE ;
				y = 13 * TILE_SCALE*TILE_SIZE ;
			}
			if (TileMap[i][j] == 'r')
			{
				x = 2 * TILE_SCALE*TILE_SIZE;
				y = 13 * TILE_SCALE*TILE_SIZE;
			}
			if(TileMap[i][j]=='S')
			{
				TileMap[i][j] = '0';
				score += 50;
				isEatable = true;
				CookieCount += 1;
			}
			if ( TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8' || TileMap[i][j] == '9' || TileMap[i][j] == 'a' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'd' || TileMap[i][j] == 'e' || TileMap[i][j] == 'f' || TileMap[i][j] == 'g' || TileMap[i][j] == 'h')
			{
				if (dy>0)
				{
					y = i * (TILE_SCALE*TILE_SIZE) - h*PLAYER_SCALE;
					dy = 0;
				}
				if (dy<0)
				{
					y = i * (TILE_SCALE*TILE_SIZE) + (TILE_SCALE*TILE_SIZE);
					dy = 0;
				}
				if (dx>0)
				{
					x = j * (TILE_SCALE*TILE_SIZE) - w*PLAYER_SCALE;
					dx = 0;
				}
				if (dx < 0)
				{
					x = j * (TILE_SCALE*TILE_SIZE) + (TILE_SCALE*TILE_SIZE);
					dx = 0;
				}
			}
		}
}

bool Player::CollideTheWall()
{
	for (int i = (y) / (TILE_SCALE*TILE_SIZE); i < (y + h*PLAYER_SCALE) / (TILE_SCALE*TILE_SIZE); i++)
		for (int j = (x) / (TILE_SCALE*TILE_SIZE); j < (x + w*PLAYER_SCALE) / (TILE_SCALE*TILE_SIZE); j++)
			if (TileMap[i][j] == 'S' || TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8' || TileMap[i][j] == '9' || TileMap[i][j] == 'a' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'd' || TileMap[i][j] == 'e' || TileMap[i][j] == 'f' || TileMap[i][j] == 'g' || TileMap[i][j] == 'h') 
				return true;
	return false;
}

Player::Player(sf::String F, float X, float Y, float W, float H):Entity(F, X, Y,  W, H)
{
	state = stay;
	prevState = stay;
	CookieCount = 0;
	lives = 3;
	score = 0;
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
}



void Player::update(float &CurrentFrame,float time)
{
	prevState = state;
	controlPlayer(CurrentFrame, time);
		switch (state)
		{
		case right: dx = speed; dy = 0; break;
		case left: dx = -speed; dy = 0; break;
		case down: dx = 0; dy = speed; break;
		case up: dx = 0; dy = -speed; break;
		case stay: dx = 0; dy = 0; speed = 0; break;
		}
		animation(CurrentFrame, time, state);
	x += dx * time;
	y += dy * time;
	//if (CollideTheWall())
		//state = stay;
//	speed = 0;
	sprite.setPosition(x, y);
	mapInteraction(time);
}
void Player::animation(float &CurrentFrame, float time,stateE state)
{
	switch (state)
	{
	case left:
			CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(16 * int(CurrentFrame), 16, 16, 16)); break;
	case right:
			CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(16 * int(CurrentFrame), 32, 16, 16)); break;
	case up:
			CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(16 * int(CurrentFrame), 48, 16, 16)); break;
	case down:
			CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(16 * int(CurrentFrame), 0, 16, 16)); break;
	}

}
void Player::controlPlayer(float &CurrentFrame, float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if(!CollideTheWall()){
			state = left; speed = 0.1; 
		//animation(CurrentFrame, time, left);
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!CollideTheWall()) {
			state = right; speed = 0.1; 
		//animation(CurrentFrame, time, right);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		if (!CollideTheWall()) {
			state = up; speed = 0.1; 
			//animation(CurrentFrame, time, up);
		}
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		if (!CollideTheWall()) {
			state = down; speed = 0.1; 
			//animation(CurrentFrame, time, down);
		}
		
	}

}



Player::~Player()
{
}
