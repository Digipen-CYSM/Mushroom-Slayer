#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
void loadImg(void);
void drawBg(void);
void drawConfrim(void);
void drawEnemyCard(int* turns);
void confirmPressed(int* handCheck, CardType* hand, Player* player, Enemy* enemy, int handSize,CardType* deck, int pressed, int* turns);