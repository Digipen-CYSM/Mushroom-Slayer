#pragma once

typedef struct Enemy {
	int health;
	int mana;
} Enemy;

Enemy mushRoom(void);
void hpLoadE(void);
void drawHealthSrcE(Enemy enemy);