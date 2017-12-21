#pragma once
#include "Map.h"
#include "Utils.h"
bool isEatable = false;

class Entity
{
public:
	float x, y, w, h, dx, dy, speed, moveTimer;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	bool CollideTheWall();
	Entity(String F, float X, float Y, float W, float H);
	~Entity();
};

