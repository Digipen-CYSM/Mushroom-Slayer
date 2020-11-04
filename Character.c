#include "cprocessing.h"

typedef struct Player {
	int health;
	int mana;
} Player;

Player createCharacter(void) 
{
	Player player1;
	player1.health = 20;
	player1.mana = 3;
	return player1;
}
