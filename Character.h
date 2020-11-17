#pragma once
#include <stdbool.h>

typedef struct Player {
	int health;
	int mana;
	int defence;
	bool abnormal_status;
} Player;

Player createCharacter(void);
void hpAndManaLoad(void);
int drawHealthSrc(Player player);
void drawManaSrc(Player player);
void drawDefenceSrc(Player player);