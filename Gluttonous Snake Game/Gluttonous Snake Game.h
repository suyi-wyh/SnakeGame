#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>


#define SNAKESIZE  100
#define MAXWEIGHT 118      //��Ҫ��ż��  ��Ȼ���в���������� 
#define MAXHIGH 28

#define SNAKE "��"
#define FOOD "��"
#define SPEED 200
#define TRUE 1
#define FALSE 0

struct    //ʳ�������
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
static int chkeating = 0;  //�жϵ�ǰ�ƶ��Ƿ�����ʳ��
static int score;

void MoveCursor(int x,int y);   //�ƶ����
void ShowMap();  // ��ʼ����ͼ
void InitSnake();    //��ʼ����
void CreatFood();  // ����ʳ��
void EatFood();  //�Ե�ʳ��
void SnakeMove();  //���ƶ�
int ChkSnake();  // ���˶�״̬

//  �� 72  �� 80 ��75  �� 77
