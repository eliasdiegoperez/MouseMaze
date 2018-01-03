#include <stdio.h>
#include <unistd.h>

void showMaze(char maze[48][160])
{
    for(int i = 0; i < 48; i++)
	{
		for(int j = 0; j < 160; j++)
		{
			if(i == 24 && j == 0)
				printf("\x1B[31m%c", maze[i][j]);

			else if(i == 24 && j == 159)
				printf("\x1B[32m%c", maze[i][j]);

			else
				printf("\x1B[0m%c", maze[i][j]);
		}
	}
}
