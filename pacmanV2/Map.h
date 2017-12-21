#include "stdafx.h"

extern const int HEIGHT_MAP;
extern const int WIDTH_MAP;
extern const float TILE_SCALE;
extern const int TILE_SIZE;
extern const int TOLTAL_COOKIE_COUNT;
extern sf::String TileMap[27];
 
struct Node
{
	bool isUpValid;
	bool isDownValid;
	bool isLeftValid;
	bool isRightValid;
	Node()
	{
		isUpValid = isDownValid = isLeftValid = isRightValid = false;
	}
};
void drawMap(sf::RenderWindow &window, sf::Sprite s_map);

	