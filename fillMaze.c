#include <stdio.h>

int randum();

void fillMaze(char maze[48][160], int density)
{
    for(int i = 0; i < 48; i++)
    {
		for(int j = 0; j < 160; j++)
		{	 
			if(i == 24 && j == 0)
				maze[i][j] = 'M';
			
			else if(i == 23 && j == 1)
				maze[i][j] = ' ';

			else if(i == 24 && j == 1)
				maze[i][j] = ' ';

			else if(i == 25 && j == 1)
				maze[i][j] = ' ';

			else if(i == 24 && j == 159)
				maze[i][j] = 'C';

			else if(i == 23 && j == 158)
				maze[i][j] = ' ';

			else if(i == 24 && j == 158)
				maze[i][j] = ' ';

			else if(i == 25 && j == 158)
				maze[i][j] = ' ';

			else if (i == 0 || i == 47 || j == 0 || j== 159)
				maze[i][j] = 'X';

			else if (randum() < density)
				maze[i][j] = 'X';

			else
				maze[i][j] = ' ';
		}
    }

}
