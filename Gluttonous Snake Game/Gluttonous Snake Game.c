// Gluttonous Snake Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Gluttonous Snake Game.h"


void MoveCursor(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void ShowMap()
{
	for (int i = 0; i <= MAXWEIGHT; i += 2)
	{
		MoveCursor(i, 0);
		printf("□");
		MoveCursor(i,MAXHIGH);
		printf("□");
	}
	for (int i = 1; i <= MAXHIGH; i++)
	{
		MoveCursor(0, i);
		printf("□");
		MoveCursor(MAXWEIGHT, i);
		printf("□");
	}

	InitSnake();
	CreatFood();
	MoveCursor(0,MAXHIGH+1);
	printf("当前得分：");
	MoveCursor(20, MAXHIGH + 1);
	printf("%d", score);
}

void InitSnake()
{
	snake.snake_len = 3;
	snake.snake_speed = SPEED;
	snake.x[0] = MAXWEIGHT / 2 + 1;
	snake.y[0] = MAXHIGH / 2;
	for (int i = 1; i < snake.snake_len; i++)
	{
		snake.x[i] = snake.x[i - 1] - 2;
		snake.y[i] = snake.y[i - 1];
	}
	for (int i = 0; i < snake.snake_len; i++)
	{
		MoveCursor(snake.x[i], snake.y[i]);
		printf(SNAKE);
	}
}

void CreatFood()
{
	int coincide = 0;
	srand((unsigned int)time(NULL));
	do
	{
		food.food_x = rand() % (MAXWEIGHT - 2) + 2;
		food.food_y = rand() % (MAXHIGH - 1) + 1;
		for (int i = 0; i < snake.snake_len; i++)
		{
			if (food.food_x == snake.x[i] && food.food_y == snake.y[i])
			{
				coincide = 1;
				break;
			}
		}
	} while (food.food_x % 2 != 0||coincide);
		
	MoveCursor(food.food_x, food.food_y);
	printf(FOOD);
}

void EatFood()
{ 
	if (snake.x[0] == food.food_x && snake.y[0] == food.food_y)
	{
		snake.snake_len++;
		chkeating = 1;    //  当前吃到食物 
		score += 10;
		MoveCursor(20, MAXHIGH + 1);
		printf("%d",score);
		CreatFood();
	}
}

void SnakeMove()
{
	int pre_move = move;

	if (_kbhit())
	{
		fflush(stdin);
		move = _getch();
		if (move == 0 || move == 224)
			move = _getch();
	}
	if (!chkeating)    //擦除尾巴
	{
		MoveCursor(snake.x[snake.snake_len-1], snake.y[snake.snake_len-1]);
		printf("  ");
	}
	//  蛇不能反向
	if ((pre_move == 72 && move == 80)||(pre_move==80&&move==72)
		||(pre_move==75&&move==77)||(pre_move==77&&move==75))
		move = pre_move;
	for (int i = snake.snake_len-1; i >0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}

	switch (move)  //判断头向哪移动
	{
	case 72:  //  上
		snake.y[0] -= 1;
		break;
	case 80:  //  下
		snake.y[0] += 1;
		break;
	case 75:  //  左
		snake.x[0] -= 2;
		break;
	case 77:  //  右
		snake.x[0] += 2;
		break;
	}
	MoveCursor(snake.x[0],snake.y[0]);
	printf(SNAKE);
	chkeating = 0;
}

int ChkSnake()
{
	if (snake.x[0] == 0 || snake.x[0] == MAXWEIGHT || snake.y[0] == 0 || snake.y[0] == MAXHIGH)
		return FALSE;
	for (int i = 3; i < snake.snake_len; i++)
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			return FALSE;
	return TRUE;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
