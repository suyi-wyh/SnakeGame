
#include"Gluttonous Snake Game.h"

void Gaming()
{
	ShowMap();
	while (TRUE)
	{
		if (ChkSnake())
		{
			EatFood();

			SnakeMove();

			Sleep(200);
		}
		else
		{
			system("cls");
			MoveCursor(MAXWEIGHT / 2 + 1, MAXHIGH / 2);
			printf("游戏失败");
			break;
		}
	}
}
void StartGame()
{
	MoveCursor(45,0);
	printf("******************************\n");
	MoveCursor(45, 1); printf("******************************\n");
	MoveCursor(45, 2); printf("******************************\n");
	MoveCursor(45, 3); printf("**********1.开始游戏**********\n");
	MoveCursor(45, 4); printf("**********2.退出游戏**********\n");
	MoveCursor(45, 5); printf("******************************\n");
	MoveCursor(45, 6); printf("******************************\n");
	MoveCursor(45, 7); printf("******************************\n");
	switch (getchar())
	{
	case 49:
		system("cls");
		Gaming();
		break;
	case 50:
		printf("游戏结束\n");
		return ;
	default:
		printf("输入错误");
	}
}



int main()
{
	StartGame();
}
