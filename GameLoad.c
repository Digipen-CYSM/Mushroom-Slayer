#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include "GameLoad.h"
CP_Image confirmButton, backGround, enemyImg, healthImg, playerImg;


void loadImg(void) {
	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
	//load background img
	backGround = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
	//load enemy img
	enemyImg = CP_Image_Load("Assets/enemy/ms1.png");

	playerImg = CP_Image_Load("Assets/character/Character.png");
}

void drawBg(void) {
	CP_Image_Draw(backGround, 850, 600, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() + 300, 255);
	//enemy image
	CP_Image_Draw(enemyImg, 1300, 470, 300, 400, 255);
	//player image
	CP_Image_Draw(playerImg, 400, 470, 270, 370, 255);
}
