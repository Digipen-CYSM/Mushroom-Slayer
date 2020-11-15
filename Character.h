#pragma once

typedef struct Player {
	int health;
	int mana;
} Player;

Player createCharacter(void);
void hpAndManaLoad(void);
int drawHealthSrc(int health);
void drawManaSrc(int mana);