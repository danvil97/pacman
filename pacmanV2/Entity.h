#pragma once
#include "Map.h"
#include "Utils.h"

extern bool isEatable;
class Entity
{
public:
	float x, y, w, h, dx, dy, speed, moveTimer;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	bool CollideTheWall();
	Entity(sf::String F, float X, float Y, float W, float H);
	~Entity();
};

