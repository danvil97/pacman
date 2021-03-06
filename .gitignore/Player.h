#pragma once
#include "stdafx.h"
using namespace sf;
#include "Entity.h"

const float PLAYER_SCALE = 1.5;
class Player:
	public Entity
{
	enum stateE {
		left,
		right,
		up,
		down,
		stay
	};
public:
	stateE state;
	stateE prevState;
	bool isUpAvaliable();
	bool isDownAvaliable();
	bool isLeftAvaliable();
	bool isRightAvaliable();

	int dir,score;
	int lives;
	int CookieCount;
	Player(String F, float X, float Y, float W, float H);
	void update(float &CurrentFrame,float time);
	void controlPlayer(float &CurrentFrame,float time);
	void mapInteraction(float time);
	void animation(float &CurrentFrame, float time,stateE);
	bool CollideTheWall();
	//bool iCanMove();
	~Player();
};

