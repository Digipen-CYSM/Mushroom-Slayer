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
int timeCheck = 0;

void Game_Init(void)
{
	memset(handCheck, 0, sizeof(int) * 5);
	handCheckP = handCheck;
	enemyMove = 0;
	handSize = 5;
	turn = 1;
	turns = &turn;
	time = 0;

	//load bg, char, enemy src
	loadImg();

	//create character
	player = createCharacter();
	playerPtr = &player;

	//create enemy
	enemy = mushRoom();
	enemyPtr = &enemy;

	//generate deck array
	deck = generateDeck(deck);

	//generate card in hand
	hand = (CardType*)malloc(playerPtr->handSize * sizeof(CardType));
	drawCards(deck, playerPtr->handSize, 1,hand);

	//load deck img src
	loadDeckImg(deck, 10,1);

	//load player hp and mana img src
	hpAndManaLoad();

	//load enemy img src
	hpLoadE();

	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");

	
}


void Game_Update(void)
{	
	time += CP_System_GetDt();
	//animation for card draw

	//draw background, char, enemy
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

	//selected hand collision
	handsCollision(selectedCount, handCheckP, playerPtr, hand);

	//draw hand src
	drawDeck(deck, playerPtr->deckSize);
	if ((int)time > 2) {
		drawHandSrc(handCheckP, selectedCount);
	}
	

	//confirm button logic
	confirmPressed(handCheckP, hand, playerPtr, enemyPtr, handSize, deck, pressed, turns);

	if (enemyPtr->health <= 0)
	{
		selected_perks(playerPtr, deck);
	}
	
	
}

void Game_Exit(void) {

}
