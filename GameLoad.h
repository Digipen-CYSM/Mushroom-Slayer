#include "Cards.h"
#include "Character.h"
#include "Enemy.h"

int round_count;
bool poison;

void loadImg(int stage);
void drawBg(int frame);
void drawConfrim(void);
void drawEnemyCard(int* turns);
void confirmPressed(int* handCheck, CardType* hand, Player* player, Enemy* enemy, int handSize,CardType* deck, int pressed, int* turns);
void freeImg(int stage);