
#include"Gluttonous Snake Game.h"

void Gaming()
{
	ShowMap();
	while (TRUE)
	{
		if (ChkSnake())
		{
			SnakeMove();
			EatFood();

			Sleep(200);
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
