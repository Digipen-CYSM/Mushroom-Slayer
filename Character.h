#pragma once
#include <stdbool.h>

typedef struct Player {
	bool poison;
	int life;
	int health;
	int mana;
	int defence;	
	int handSize;
	int deckSize;
	int oMana;
} Player;

Player createCharacter(void);
void hpAndManaLoad(void);
void drawHealthSrc(Player player);
void drawManaSrc(Player player);
void draw_poison_status(Player player);
void drawDefenceSrc(Player player);
void takeDamage(Player* player, int damage);

Player* playerPtr;