#include <stdio.h>

int frontBlocked(char map[48][160], int x, int y, char direction)
{
    int result = 0;
    
    switch(direction)
    {
	case 'E': 
  	    if(map[y][x+1] == 'X')
	        result = 1;
	    break;
	case 'S': 
	    if(map[y+1][x] == 'X')
		result = 1;
	    break;
	case 'W':
	    if(map[y][x-1] == 'X')
		result = 1;
	    break;
	case 'N':
	    if(map[y-1][x] == 'X')
		result = 1;
	    break;
    }

    return result;

}
