#pragma once

typedef struct Player {
	int health;
	int mana;
	int defence;
} Player;

Player createCharacter(void);
void hpAndManaLoad(void);
int drawHealthSrc(Player player);
void drawManaSrc(Player player);
void drawDefenceSrc(Player player);