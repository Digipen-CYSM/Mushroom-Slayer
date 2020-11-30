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

void level1_1_Init(void){
	//load bg, char, enemy src
	loadImg();

	free(hand);
	hand = (CardType*)malloc(playerPtr->handSize * sizeof(CardType));
	
	drawCards(deck, playerPtr->handSize, 2,hand);

	//create enemy
	enemy = mushRoom();
	enemyPtr = &enemy;

	//load deck img src
	loadDeckImg(deck, playerPtr->deckSize,0);

	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
}

void level1_1_Update(void) {

	drawBg();
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
	drawHandSrc(handCheckP, selectedCount);
	confirmPressed(handCheckP, hand, playerPtr, enemyPtr, handSize, deck, pressed, turns);
}

void level1_1_Exit(void) {

}