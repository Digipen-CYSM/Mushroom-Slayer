#include "cprocessing.h"
#include "game.h"
#include "Cards.h"
#include <string.h>
#include <stdio.h>
#include "GameOver.h"
#include "GameLoad.h"
#include "Character.h"
#include "Enemy.h"
#include "Perks.h"
#include <stdlib.h>

//global variable
float animateBG = 0;
int j = 0;

void level1_1_Init(void){
	//load bg, char, enemy src
	loadImg(1);
	free(hand);
	perks_loading_count = 30;
	perks_count_bool = 1;
	perks_level_count = 1;
	frame_count = 0;
	
	hand = (CardType*)malloc(playerPtr->handSize * sizeof(CardType));
	
	drawCards(deck, playerPtr->handSize, 2,hand);
	
	//create enemy
	enemy = mushRoom1();
	enemyPtr = &enemy;

	//load deck img src
	loadDeckImg(deck, playerPtr->deckSize,0);

	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
}

void level1_1_Update(void) {
	
	frame_count++;
	animateBG += CP_System_GetDt();
	if (animateBG >= 0.6f) {
		j++;
	}
	if(j == 4){
		j = 0;
	}
	
	drawBg(j);
	drawEnemyCard(turns);
	//draw player health, mana, defence
	drawHealthSrc(player);
	drawManaSrc(player);
	drawDefenceSrc(player);

	//draw enemy hp
	drawHealthSrcE(enemy);

	int selectedCount = 0;
	int pressed = 0;

	//unselected hand collision
	handuCollision(hand, playerPtr, handCheckP);

	//count selected cards
	for (int i = 0; i < 5; i++) {
		if (handCheckP[i] == 1) {
			selectedCount += 1;
		}
	}

	//draw cfm button
	if (selectedCount > 0) {
		drawConfrim();
		pressed = 1;
	}
	drawDeck(deck, playerPtr->deckSize);
	//selected hand collision
	handsCollision(selectedCount, handCheckP, playerPtr, hand);
	drawHandSrc(handCheckP, selectedCount, playerPtr->handSize);
	confirmPressed(handCheckP, hand, playerPtr, enemyPtr, handSize, deck, pressed, turns);

	if (enemyPtr->health <= 0)
	{
		CP_Engine_SetNextGameState(game_over_init, game_over_update, game_over_exit);
	}

	if (poison == true)
	{
		draw_poison_effect();
	}

	if (playerPtr->health <= 0)
	{
		if (playerPtr->life > 1)
		{
			playerPtr->health = 5;
		}
		else
		{
			CP_Engine_SetNextGameState(game_over_init, game_over_update, game_over_exit);
		}
	}
}

void level1_1_Exit(void) {
	*turns = 1;
	freeImg(1);
}