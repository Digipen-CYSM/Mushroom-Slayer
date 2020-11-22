#pragma once
#include <stdbool.h>

typedef struct Player {
	int life;
	int health;
	int mana;
	int defence;
	bool poison;
} Player;

Player createCharacter(void);
void hpAndManaLoad(void);
int drawHealthSrc(Player player);
void drawManaSrc(Player player);
void drawDefenceSrc(Player player);
void takeDamage(Player* player, int damage);