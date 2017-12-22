#include "stdafx.h"
#include "Map.h"
using namespace sf;

const int HEIGHT_MAP = 27;
const int WIDTH_MAP = 21;
const float TILE_SCALE = 1.5;
const int TILE_SIZE = 16;
const int TOLTAL_COOKIE_COUNT = 229 ;

sf::String TileMap[HEIGHT_MAP] =
{ "522222222242222222226",
"1Sjjjjjjjj1jjjjjjjjS1",
"1j526j526j1j526j526j1",
"1j101j101j1j101j101j1",
"1j827j827j3j827j827j1",
"1jjjjjjjjjjjjjjjjjjj1",
"1j526jaj52226jaj526j1",
"1j827j1j82427j1j827j1",
"1jjjjj1jjj1jjj1jjjjj1",
"82226jb2cj3j92dj52227",
"00001j1jjjjjjj1j10000",
"00001j1j5fgh6j1j10000",
"92227j3j10001j3j8222c",
"0ljjjjjj1l001jjjjjjr0",
"92226jaj82227jaj5222c",
"00001j1jjjjjjj1j10000",
"00001j1j52226j1j10000",
"52227j3j82427j3j82226",
"1jjjjjjjjj1jjjjjjjjj1",
"1j926j92cj3j92cj52cj1",
"1Sjj1jjjjjjjjjjj1jjS1",
"b26j1jaj52226jaj1j52d",
"b27j3j1j82427j1j3j82d",
"1jjjjj1jjj1jjj1jjjjj1",
"1j9222e2cj3j92e222cj1",
"1jjjjjjjjjjjjjjjjjjj1",
"822222222222222222227"
};
void drawMap(sf::RenderWindow &window, sf::Sprite s_map)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == '0') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 0, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '1') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 1, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '2') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 2, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '3') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 3, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '4') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 4, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '5') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 5, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '6') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 6, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '7') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 7, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '8') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 8, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == '9') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 9, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'a') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 10, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'b') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 11, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'c') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 12, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'd') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 13, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'e') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 14, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'f') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 15, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'g') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 16, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'h') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 17, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'j') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 18, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'l') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 0, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'r') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 0, 0, TILE_SIZE, TILE_SIZE));
			if (TileMap[i][j] == 'S') s_map.setTextureRect(sf::IntRect(TILE_SIZE * 19, 0, TILE_SIZE, TILE_SIZE));
			s_map.setPosition(j * (TILE_SCALE*TILE_SIZE), i*(TILE_SCALE*TILE_SIZE));
			s_map.setScale(TILE_SCALE, TILE_SCALE);
			window.draw(s_map);
		}
}