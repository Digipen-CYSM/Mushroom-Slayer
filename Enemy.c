//---------------------------------------------------------
// file:	Enemy.c
// author:	Marcus Chong
//			Chia Shi Bo
//
// email:	youlongmarcus.c@digipen.edu
//			
//
// brief:	functions for enemy
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "Character.h"
CP_Image healthSrcE;

//Done By: Marcus
typedef struct Enemy {
	int health;	
} Enemy;

//Done By: Marcus
Enemy mushRoomT(void)
{
	Enemy mushroom;
	mushroom.health = 10;
	return mushroom;
}

//Done By: Marcus
Enemy mushRoom1(void)
{
	Enemy mushroom;
	mushroom.health = 30;
	return mushroom;
}

//Done By : Marcus
void hpLoadE(void) {
	healthSrcE = CP_Image_Load("Assets/hpnshield/hp.png");
}

//Done By: Chia Shi Bo
void drawHealthSrcE(Enemy enemy) {
	float eHealthWidth = 1710;
	for (int i = 0; i < enemy.health; i++) {
		eHealthWidth -= 40;
		if (i == 10 || i == 20) {
			eHealthWidth = 1670;
		}
		if (i < 10) 
		{
			CP_Image_Draw(healthSrcE, eHealthWidth, 30, 40, 40, 255);
		}
		else if ( i > 9 && i < 20) 
		{
			CP_Image_Draw(healthSrcE, eHealthWidth, 75, 40, 40, 255);
		}
		else if (i > 19)
		{
			CP_Image_Draw(healthSrcE, eHealthWidth, 120, 40, 40, 255);
		}
	}
}

//Done By: Marcus
void enemyAttack(Player* player, int damage) {
	if (player->defence < damage) {
		player->health -= damage - player->defence;
		player->defence = 0;
	}
	else if (player->defence > damage) {
		player->defence -= damage;
	}
	else {
		player->defence = 0;
	}
}