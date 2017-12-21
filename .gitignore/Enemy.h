#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	int randomMove;
	void update(float &CurrentFrame, float time);
	//void animation(float &CurrentFrame, float time);
	Enemy(String F, float X, float Y, float W, float H);
	void mapInteraction(float time);
	~Enemy();
};

