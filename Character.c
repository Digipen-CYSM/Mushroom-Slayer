//---------------------------------------------------------
// file:	Character.c
// author:	Chia Shi Bo
//			Zhuo Yijian
//			Marcus Chong
//
// email:	
//			yijian.zhuo@digipen.edu
//			youlongmarcus.c@digipen.edu
//
// brief:	function for character
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "Character.h"
CP_Image healthSrc;
CP_Image defenceSrc;
CP_Image poison_source;
CP_Image manaSrc[10];
char manaStr2[10];

//Done by: Marcus
Player createCharacter(void) 
{
	Player player1;
	player1.life = 1;
	player1.health = 20;
	player1.mana = 3;
	player1.oMana = 3;
	player1.defence = 0;
	player1.handSize = 5;
	player1.deckSize = 10;
	playerPtr = &player1;
	return player1;
}

//Done by: Chia Shi bo
void hpAndManaLoad(void) {
	healthSrc = CP_Image_Load("Assets/hpnshield/hp.png");
	defenceSrc = CP_Image_Load("Assets/hpnshield/shield.png");
	poison_source = CP_Image_Load("Assets/poison/poisondmg.png");
	for (int i = 0; i < 10; i++) {
		char str[100] = "Assets/manaBar/mana";
		int manaStr = 48+i;
		manaStr2[0] = (char)manaStr;
		strcat_s(str, sizeof(str), manaStr2);
		strcat_s(str, sizeof(str), ".png");
		manaSrc[i] = CP_Image_Load(str);
	}
	
}

//Done by: Chia Shi bo
void drawHealthSrc(Player player) {
	float pHealthWidth = 30;
	for (int i = 0; i < player.health; i++) {		
		if (i == 10 || i == 20) {
			pHealthWidth = 30;
		}
		if (i < 10) {
			CP_Image_Draw(healthSrc, pHealthWidth, 30, 40, 40, 255);
		}
		else if(i<20){
			CP_Image_Draw(healthSrc, pHealthWidth, 75, 40, 40, 255);
		}
		else {
			CP_Image_Draw(healthSrc, pHealthWidth, 120, 40, 40, 255);
		}
		pHealthWidth += 40;
	}
}

//Done by: Chia Shi bo
void drawDefenceSrc(Player player) {
	float defenceWidth, defenceHeight;
	if (player.health <= 10) {
		defenceHeight = 75;
	}
	else if (player.health <= 20) {
		defenceHeight = 120;
	}
	else {
		defenceHeight = 165;
	}
	defenceWidth = 30;
	for (int i = 0; i < player.defence; i++) {
		CP_Image_Draw(defenceSrc, defenceWidth, defenceHeight, 40, 40, 255);
		defenceWidth += 40;
	}
}

//Done by: Yijian
void draw_poison_status(Player player)
{
	float poison_Height;
	if (player.health <= 10) {
		poison_Height = 120;
	}
	else if (player.health <= 20) {
		poison_Height = 165;
	}
	else {
		poison_Height = 210;
	}
	CP_Image_Draw(poison_source, 30, poison_Height, 40, 40, 255);
}

//Done by: Chia Shi bo
void drawManaSrc(Player player) {
	CP_Image_Draw(manaSrc[player.mana], 50, 660, 50, 400, 255);
}

//Done by: Chia Shi bo
void takeDamage(Player* player, int damage) {
	if (player->defence < damage) {
		player->defence = 0;
		player->health = damage - player->defence;
	}
	else if (player->defence > damage) {
		player->defence -= damage;
	}
	else {
		player->defence = 0;
	}
}
