#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>


#define SNAKESIZE  100
#define MAXWEIGHT 118      //需要是偶数  不然会有不对齐的问题 
#define MAXHIGH 28

#define SNAKE "■"
#define FOOD "★"
#define SPEED 200
#define TRUE 1
#define FALSE 0

struct    //食物的坐标
{
	int food_x;
	int food_y;
}food;

struct
{
	int snake_len;
	int snake_speed;
	int x[SNAKESIZE];
	int y[SNAKESIZE];
}snake;

static int move = 77;
static int chkeating = 0;  //判断当前移动是否碰到食物
static int score;

void MoveCursor(int x,int y);   //移动光标
void ShowMap();  // 初始化地图
void InitSnake();    //初始化蛇
void CreatFood();  // 插入食物
void EatFood();  //吃到食物
void SnakeMove();  //蛇移动
int ChkSnake();  // 蛇运动状态

//  上 72  下 80 左75  右 77
