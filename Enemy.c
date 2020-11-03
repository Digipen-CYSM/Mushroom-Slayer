#include "cprocessing.h"

typedef struct Enemy {
	int health;
	int mana;
} Enemy;

Enemy mushRoom(void)
{
	Enemy mushroom;
	mushroom.health = 20;
	mushroom.mana = 3;
	return mushroom;
}