#include "Entity.h"

bool isEatable = false;

bool Entity::CollideTheWall()
{
	for (int i = (y + 2) / (TILE_SCALE*TILE_SIZE); i < (y + h*1.5) / (TILE_SCALE*TILE_SIZE); i++)
		for (int j = (x + 2) / (TILE_SCALE*TILE_SIZE); j < (x + w*1.5) / (TILE_SCALE*TILE_SIZE); j++)
			if (TileMap[i][j] == 'S' || TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == '8' || TileMap[i][j] == '9' || TileMap[i][j] == 'a' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'd' || TileMap[i][j] == 'e' || TileMap[i][j] == 'f' || TileMap[i][j] == 'g' || TileMap[i][j] == 'h')
				return true;
	return false;
}

Entity::Entity(sf::String F, float X, float Y, float W, float H)
{
	dx = 0; dy = 0; speed = 0;
	File = F;
	w = W; h = H;
	image.loadFromFile("images/" + File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
}


Entity::~Entity()
{
}
