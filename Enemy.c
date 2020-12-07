#include "cprocessing.h"
#include "Character.h"
CP_Image healthSrcE;

//Marcus
typedef struct Enemy {
	int health;	
} Enemy;

//Marcus
Enemy mushRoomT(void)
{
	Enemy mushroom;
	mushroom.health = 5;
	return mushroom;
}

//Marcus
Enemy mushRoom1(void)
{
	Enemy mushroom;
	mushroom.health = 10;
	return mushroom;
}

void hpLoadE(void) {
	healthSrcE = CP_Image_Load("Assets/hpnshield/hp.png");
}

void drawHealthSrcE(Enemy enemy) {
	float eHealthWidth = 1670;
	for (int i = 0; i < enemy.health; i++) {
		if (i == 10) {
			eHealthWidth = 1670;
		}
		if (i < 10) {
			CP_Image_Draw(healthSrcE, eHealthWidth, 30, 40, 40, 255);
		}
		else {
			CP_Image_Draw(healthSrcE, eHealthWidth, 75, 40, 40, 255);
		}

		eHealthWidth -= 40;

	}
}

//Marcus
void enemyAttack(Player* player, int damage) {
	if (player->defence < damage) {
		player->health -= damage - player->defence;
		player->defence = 0;
	}
	else if (player->defence > damage) {
		player->defence -= damage;
	}
	else {
		player->defence = 0;
	}
}