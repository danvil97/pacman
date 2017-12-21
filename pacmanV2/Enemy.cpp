#include "Enemy.h"

void Enemy::update(float & CurrentFrame, float time)
{
	//animation(CurrentFrame, time);

	x += dx*time;
	y += dy*time;

	//	speed = 0;
	sprite.setPosition(x, y);
	mapInteraction(time);
}

Enemy::Enemy(sf::String F, float X, float Y, float W, float H):Entity(F,X,Y,W,H)
{
	srand(time(NULL));
	randomMove = 1;
	dx = 0; dy = 0.05; speed = 0.05;
	File = F;
	w = W; h = H;
	image.loadFromFile("images/" + File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setScale(1.5, 1.5);
}

void Enemy::mapInteraction(float time)
{
	for (int i = (y) / (TILE_SCALE*TILE_SIZE); i < (y + h*1.5) / (TILE_SCALE*TILE_SIZE); i++)
		for (int j = (x) / (TILE_SCALE*TILE_SIZE); j < (x + w*1.5) / (TILE_SCALE*TILE_SIZE); j++)
		{
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
			if (TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8' || TileMap[i][j] == '9' || TileMap[i][j] == 'a' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'd' || TileMap[i][j] == 'e' || TileMap[i][j] == 'f' || TileMap[i][j] == 'g' || TileMap[i][j] == 'h')
			{
				if (dy>0)
				{
					y = i * (TILE_SCALE*TILE_SIZE) - h*1.5;
					dy = 0;
					if (rand() % 2>0)
						dx = speed;
					else
						dx = -speed;
				}
				else if (dy<0)
				{
					y = i * (TILE_SCALE*TILE_SIZE) + (TILE_SCALE*TILE_SIZE);
					dy = 0;
					if (rand() % 2>0)
						dx = speed;
					else
						dx = -speed;
				}
				else if (dx>0)
				{
					x = j * (TILE_SCALE*TILE_SIZE) - w*1.5;
					dx = 0;
					if (rand() % 2>0)
						dy = speed;
					else
						dy = -speed;
				}
				else if (dx < 0)
				{
					x = j * (TILE_SCALE*TILE_SIZE) + (TILE_SCALE*TILE_SIZE);
					dx = 0; if (rand() % 2>0)
						dy = speed;
					else
						dy = -speed;
				}
			}
		}
}

Enemy::~Enemy()
{
}
