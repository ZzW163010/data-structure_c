#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
#define SNAKE_NUM_MAX 500


enum DIR {
	UP,
	DOWN,
	RIGHT,
	LEFT
};
struct Snake {
	int size;		//蛇的节数
	int dir;		//方向
	int speed;		//速度
	POINT coor[SNAKE_NUM_MAX];		//坐标
}snake;
struct Food {
	int x;
	int y;
	int r;
	bool flag;
	DWORD color;
}food;

void GameInit()
{
	//mciSendString("open snake_bgm.mp3 alias BGM", 0, 0, 0);
	//mciSendString("play BGM repeat", 0, 0, 0);
	initgraph(640, 480);
	srand(GetTickCount());
	snake.size = 3;
	snake.speed = 10;
	snake.dir = LEFT;
	for (int i = 0; i < snake.size; i++) {
		snake.coor[i].x = 40 - i * 10;
		snake.coor[i].y = 10;
	}
	food.x = rand() % 400;
	food.y = rand() % 400;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = rand() % 10 + 5;
	food.flag = 1;
}
void GameDraw() {
	BeginBatchDraw();
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	setfillcolor(RGB(212, 242, 231));

	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	if (food.flag) {
		setfillcolor(food.color);
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}
//移动蛇
void snakeMove()
{
	for (int i = snake.size - 1; i >= 1; i--) {
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir) {
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y == 0) {
			snake.coor[0].y = 480;
		}
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y == 480) {
			snake.coor[0].y = 0;
		}
		break;
	case RIGHT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x == 0) {
			snake.coor[0].x = 640;
		}
		break;
	case LEFT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x == 640) {
			snake.coor[0].x = 0;
		}
		break;
	}
}
void keyControl() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
		case'W':
		case 72:
			if (snake.dir != DOWN) {
				snake.dir = UP;
			}
			break;
		case's':
		case 'S':
		case 80:
			if (snake.dir != UP) {
				snake.dir = DOWN;
			}
			break;
		case'a':
		case'A':
		case 75:
			if (snake.dir != LEFT) {
				snake.dir = RIGHT;
			}
			break;
		case'D':
		case'd':
		case 77:
			if (snake.dir != RIGHT) {
				snake.dir = LEFT;
			}
			break;
		}
	}
}
void EatFood()
{
	if (food.flag && (snake.coor[0].x >= food.x - food.r && snake.coor[0].x <= food.x + food.r) &&
		(snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r)) {
		food.flag = 0;
		snake.size++;
	}
	if (!food.flag) {
		food.x = rand() % 400;
		food.y = rand() % 400;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = 1;
	}
}
void stop() {
	if (_kbhit()) {
		if (_getch() == ' ') {
			while (_getch() != ' ');
		}
	}
}
int out() {

	//for (int i = 1; i < snake.size - 1; i++) {
	//	if (snake.coor[0].x >= snake.coor[i].x - 2.5 && snake.coor[0].x <= snake.coor[i].x + 2.5 &&
	//		snake.coor[0].y >= snake.coor[i].y - 2.5 && snake.coor[0].y <= snake.coor[i].y + 2.5 ||
	//		snake.coor[0].x >= snake.coor[i + 1].x - 2.5 && snake.coor[0].x <= snake.coor[i + 1].x + 2.5 &&
	//		snake.coor[0].y >= snake.coor[i + 1].y - 2.5 && snake.coor[0].y <= snake.coor[i + 1].y + 2.5) {
	//		return 0;
	//	}
	//	return 1;
	//}
	if (snake.coor[0].x >= snake.coor[1].x - 2.5 && snake.coor[0].x <= snake.coor[1].x + 2.5 &&
		snake.coor[0].y >= snake.coor[1].y - 2.5 && snake.coor[0].y <= snake.coor[1].y + 2.5 ||
		snake.coor[0].x >= snake.coor[2].x - 2.5 && snake.coor[0].x <= snake.coor[2].x + 2.5 &&
		snake.coor[0].y >= snake.coor[2].y - 2.5 && snake.coor[0].y <= snake.coor[2].y + 2.5 ||
		snake.coor[0].x >= snake.coor[3].x - 2.5 && snake.coor[0].x <= snake.coor[3].x + 2.5 &&
		snake.coor[0].y >= snake.coor[3].y - 2.5 && snake.coor[0].y <= snake.coor[3].y + 2.5 ||
		snake.coor[0].x >= snake.coor[4].x - 2.5 && snake.coor[0].x <= snake.coor[4].x + 2.5 &&
		snake.coor[0].y >= snake.coor[4].y - 2.5 && snake.coor[0].y <= snake.coor[4].y + 2.5 ||
		snake.coor[0].x >= snake.coor[5].x - 2.5 && snake.coor[0].x <= snake.coor[5].x + 2.5 &&
		snake.coor[0].y >= snake.coor[5].y - 2.5 && snake.coor[0].y <= snake.coor[5].y + 2.5 ||
		snake.coor[0].x >= snake.coor[6].x - 2.5 && snake.coor[0].x <= snake.coor[6].x + 2.5 &&
		snake.coor[0].y >= snake.coor[6].y - 2.5 && snake.coor[0].y <= snake.coor[6].y + 2.5 ||
		snake.coor[0].y >= snake.coor[7].y - 2.5 && snake.coor[0].y <= snake.coor[7].y + 2.5 &&
		snake.coor[0].x >= snake.coor[7].x - 2.5 && snake.coor[0].x <= snake.coor[7].x + 2.5 ||
		snake.coor[0].x >= snake.coor[8].x - 2.5 && snake.coor[0].x <= snake.coor[8].x + 2.5 &&
		snake.coor[0].y >= snake.coor[8].y - 2.5 && snake.coor[0].y <= snake.coor[8].y + 2.5 ||
		snake.coor[0].x >= snake.coor[9].x - 2.5 && snake.coor[0].x <= snake.coor[9].x + 2.5 &&
		snake.coor[0].y >= snake.coor[9].y - 2.5 && snake.coor[0].y <= snake.coor[9].y + 2.5 ||
		snake.coor[0].x >= snake.coor[10].x - 2.5 && snake.coor[0].x <= snake.coor[10].x + 2.5 &&
		snake.coor[0].y >= snake.coor[10].y - 2.5 && snake.coor[0].y <= snake.coor[10].y + 2.5){

			
			return 0;

		}
	return 1;
}
	
int main()
{

	GameInit();
	GameDraw();

	while (1) {
		stop();
		keyControl();
		GameDraw();
		snakeMove();
		EatFood();
		int ret = out();
		if (ret == 0) {
			printf("sorry! you are die!!!");
		}
		Sleep(50);
	}
}