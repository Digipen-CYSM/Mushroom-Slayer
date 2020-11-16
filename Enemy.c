#include "cprocessing.h"
CP_Image healthSrcE;
typedef struct Enemy {
	int health;	
} Enemy;

Enemy mushRoom(void)
{
	Enemy mushroom;
	mushroom.health = 20;
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