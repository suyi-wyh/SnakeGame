
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
			printf("��Ϸʧ��");
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
	MoveCursor(45, 3); printf("**********1.��ʼ��Ϸ**********\n");
	MoveCursor(45, 4); printf("**********2.�˳���Ϸ**********\n");
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
		printf("��Ϸ����\n");
		return ;
	default:
		printf("�������");
	}
}



int main()
{
	StartGame();
}
