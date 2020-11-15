#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
CP_Image healthSrc;
CP_Image manaSrc[10];
char manaStr2[10];

typedef struct Player {
	int health;
	int mana;
} Player;

Player createCharacter(void) 
{
	Player player1;
	player1.health = 20;
	player1.mana = 3;
	return player1;
}

void hpAndManaLoad(void) {
	healthSrc = CP_Image_Load("Assets/hpnshield/hp.png");
	for (int i = 0; i < 10; i++) {
		char str[100] = "Assets/manaBar/mana";
		int manaStr = 48+i;
		manaStr2[0] = (char)manaStr;
		strcat_s(str, sizeof(str), manaStr2);
		strcat_s(str, sizeof(str), ".png");
		manaSrc[i] = CP_Image_Load(str);
	}
	
}

void drawHealthSrc(int health) {
	float pHealthWidth = 30;
	for (int i = 0; i < health; i++) {		
		if (i == 10) {
			pHealthWidth = 30;
		}
		if (i < 10) {
			CP_Image_Draw(healthSrc, pHealthWidth, 30, 40, 40, 255);
		}
		else {
			CP_Image_Draw(healthSrc, pHealthWidth, 75, 40, 40, 255);
		}
		
		pHealthWidth += 40;

	}
}

void drawManaSrc(int mana) {
	CP_Image_Draw(manaSrc[mana], 50, 660, 50, 400, 255);
}
