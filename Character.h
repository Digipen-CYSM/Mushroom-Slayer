#pragma once

typedef struct Player {
	int health;
	int mana;
} Player;

Player createCharacter(void);