#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
void loadImg(int stage);
void drawBg(int frame);
void drawConfrim(void);
void drawEnemyCard(int* turns);
int confirmPressed(int* handCheck, CardType* hand, Player* player, Enemy* enemy, int handSize,CardType* deck, int pressed, int* turns);
void freeImg(int stage);
void turnAnimation(Player* player, Enemy* enemy, int frame, int* handCheckPtr, CardType* hand, int selectedCount);