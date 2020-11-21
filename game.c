#include "cprocessing.h"
#include "game.h"
#include "Cards.h"
#include <string.h>
#include <stdio.h>
#include "GameOver.h"
#include "GameLoad.h"
#include "Character.h"
#include "Enemy.h"
//global variable
float time = 0, timeFloat;
CardType* hand;
CardType* deck;
Player* playerPtr;
Player player;
Enemy* enemyPtr;
Enemy enemy;
int handCheck[5] = {0,0,0,0,0}; //change to dynamic
int* handCheckP = handCheck;
int enemyMove = 0,handSize = 5;
CP_Image confirmButton;
int turns = 1;
void Game_Init(void)
{
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
	hand = drawCards(deck, 5, 1);

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
	drawHandSrc(handCheckP, selectedCount);

	//confirm button logic
	confirmPressed(handCheckP, hand, playerPtr, enemyPtr, handSize, deck, pressed, turns);
	
	//enemy move
	//if (enemyMove == 1) {
	//	if (time < timeFloat + 3) {
	//		CP_Image_Draw(handS[0][0], 1500, 300, 200, 300, 255); //card base
	//		CP_Image_Draw(handS[0][1], 1500, 407, 170, 80, 255); //card value
	//		CP_Image_Draw(handS[0][2], 1500 - 67, 170, 41, 23, 255); //card mana
	//	}
	//	else {
	//		enemyMove = 0;
	//		pHealth -= 3;
	//	}
	//}
	//if (pHealth == 0)
	//{
	//	CP_Engine_SetNextGameState(game_over_init, game_over_update, game_over_exit);
	//}	
	
	
	

}

void Game_Exit(void) {

}
