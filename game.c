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

//global variable


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
	deck = generateDeck();

	//generate card in hand
	hand = drawCards(deck, playerPtr->handSize, 1);

	//load deck img src
	loadDeckImg(deck, 10);

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
	drawDeck(deckPtr, playerPtr->deckSize);
	drawHandSrc(handCheckP, selectedCount);

	//confirm button logic
	confirmPressed(handCheckP, hand, playerPtr, enemyPtr, handSize, deck, pressed, turns);
	
	if (enemyPtr->health <= 0)
	{
		selected_perks(playerPtr, deck);
	}
	char print[100];
	sprintf_s(print, 100, "%d", player.deckSize);
	CP_Font_DrawText(print, 830, 25);
}

void Game_Exit(void) {

}
