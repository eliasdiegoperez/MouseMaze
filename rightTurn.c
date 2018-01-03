#include <stdio.h>

char rightTurn(char direction)
{
    char newDirection;
    switch(direction)
    {
	case 'N': newDirection = 'E';
	    break;
	case 'E': newDirection = 'S';
	    break;
	case 'S': newDirection = 'W';
	    break;
	case 'W': newDirection = 'N';
	    break;
    }

	return newDirection;
}
