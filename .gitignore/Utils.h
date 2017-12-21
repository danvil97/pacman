#pragma once

//game states
#define PAUSE 0
#define DEATH 1
#define MENU 2
#define PLAY 3

void getRandomMove(int &randomMove) 
{
	int tmp = 0;
	tmp = rand() % 2;
	//if (tmp == 0)
		//tmp = -1;
}