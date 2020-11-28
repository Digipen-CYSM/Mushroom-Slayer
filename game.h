#include "Cards.h"
#include "Character.h"
#include "Enemy.h"

void Game_Init(void);
void Game_Update(void);
void Game_Exit(void);

float time, timeFloat;
CardType* hand;
CardType* deck;
Player* playerPtr;
Player player;
Enemy* enemyPtr;
Enemy enemy;
int handCheck[5];
int* handCheckP;
int enemyMove, handSize;
CP_Image confirmButton;
int turn;
int* turns;
