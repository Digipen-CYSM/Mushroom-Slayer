#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

CP_Image healthSrc;
CP_Image defenceSrc;
CP_Image manaSrc[10];
char manaStr2[10];

typedef struct Player {
	int health;
	int mana;
	int defence;
	bool poison;
} Player;

Player createCharacter(void) 
{
	Player player1;
	player1.health = 20;
	player1.mana = 3;
	player1.defence = 0;
	return player1;
}

void hpAndManaLoad(void) {
	healthSrc = CP_Image_Load("Assets/hpnshield/hp.png");
	defenceSrc = CP_Image_Load("Assets/hpnshield/shield.png");
	for (int i = 0; i < 10; i++) {
		char str[100] = "Assets/manaBar/mana";
		int manaStr = 48+i;
		manaStr2[0] = (char)manaStr;
		strcat_s(str, sizeof(str), manaStr2);
		strcat_s(str, sizeof(str), ".png");
		manaSrc[i] = CP_Image_Load(str);
	}
	
}

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

void drawManaSrc(Player player) {
	CP_Image_Draw(manaSrc[player.mana], 50, 660, 50, 400, 255);
}

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
