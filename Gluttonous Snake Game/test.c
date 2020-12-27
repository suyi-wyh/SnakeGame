
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
			Sleep(500);
		}
		else
		{
			system("cls");
			MoveCursor(MAXWEIGHT / 2 + 1, MAXHIGH / 2);
			printf("”Œœ∑ ß∞‹");
			break;
		}
	}
}

int main()
{
	Gaming();
}
