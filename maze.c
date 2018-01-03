#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void showMaze(char[48][160]);
int rightsideBlocked(char[48][160], int, int, char);
int leftsideBlocked(char[48][160], int, int, char);
int frontBlocked(char[48][160],int,int,char);
char leftTurn(char);
void fillMaze(char maze[48][160],int);
int randum();
char rightTurn(char);


int main()
{
	srand( time(NULL) );
    char maze[48][160];
    int density, delay, print,val;
	char mouse = 'M';
	int current = 24;
	int point = 1;
	int steps = 0;
	char direction = 'E';

	printf("Welcome to the Mickey Mouse Maze by Elias Perez\n");

	printf("Enter percent of density: ");
	scanf("%d", &density);

	printf("Enter the mouse delay in milliseconds: ");
	scanf("%d", &delay);
	fillMaze(maze,density);  

	printf("\n\nThank you.  Here is the maze.  Mickey will begin his travel in 5 seconds.\n");
	showMaze(maze);
	printf("Please wait...");
	fflush(stdout);
	sleep(5);
	fflush(stdout);
	printf("\033[2J");
	printf("\033[1;1H");

	showMaze(maze);
	
	while(point != 159 && point != 0)
	{
		printf("\033[25;1H\x1B[34m%c", mouse);
		printf("\033[25;2H\x1B[34m%c", mouse);
		switch(direction)
		{
			case 'E':
				if(rightsideBlocked(maze,point,current,direction) == 1)
				{
					if(frontBlocked(maze,point,current,direction) == 0)
					{
						point++;
					}
					else if(leftsideBlocked(maze,point,current,direction) == 0)
					{
						direction = leftTurn(direction);
						current--;
					}
					else
					{
						direction = leftTurn(direction);
						direction = leftTurn(direction);
						point--;
					}
					maze[current][point] = mouse;
				}
				else
				{
					direction = rightTurn(direction);
					current++;
					maze[current][point] = mouse;
				}
				break;

			case 'S':
				if(rightsideBlocked(maze,point,current,direction) == 1)
				{
					if(frontBlocked(maze,point,current,direction) == 0)
					{
						current++;
					}
					else if(leftsideBlocked(maze,point,current,direction) == 0)
					{
						direction = leftTurn(direction);
						point++;
					}
					else
					{
						direction = leftTurn(direction);
						direction = leftTurn(direction);
						current--;
					}
					maze[current][point] = mouse;
				}
				else
				{
					direction = rightTurn(direction);
					point--;
					maze[current][point] = mouse;
				
				}
				break;

			case 'W':
				if(rightsideBlocked(maze,point,current,direction) == 1)
				{
					if(frontBlocked(maze,point,current,direction) == 0)
					{
						point--;
					}
					else if(leftsideBlocked(maze,point,current,direction) == 0)
					{
						direction = leftTurn(direction);
						current++;
					}
					else
					{
						direction = leftTurn(direction);
						direction = leftTurn(direction);
						point++;
					}
					maze[current][point] = mouse;
				}
				else
				{
					direction = rightTurn(direction);
					current--;
					maze[current][point] = mouse;
				}
				break;

			case 'N':
				if(rightsideBlocked(maze,point,current,direction) == 1)
				{
					if(frontBlocked(maze,point,current,direction) == 0)
					{
						current--;
					}
					else if(leftsideBlocked(maze,point,current,direction) == 0)
					{
						direction = leftTurn(direction);
						point--;
					}
					else
					{
						direction = leftTurn(direction);
						direction = leftTurn(direction);
						current++;

					}

					maze[current][point] = mouse;
				}
				else
				{
					direction = rightTurn(direction);
					point++;
					maze[current][point] = mouse;
				}
				break;

		}
		steps++;

		val = point+1;
		print = current+1;

		usleep(delay*1000);
		printf("\033[%d;%dH\x1B[31m%c\x1b[0m",print,val, maze[current][point]);
		fflush(stdout);

		printf("\033[%d;%dH\x1B[34m%c\x1b[0m",print,val, maze[current][point]);
		
		printf("\033[50;0H");
		printf("\x1B[0mThe amount of steps were: %d", steps);
		
	}
	

	if(point == 159)
		printf("                            Conclusion: Success\n");
	else
		printf("                            Conclusion: Failed\n");

	return 0;

}
