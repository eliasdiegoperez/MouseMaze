#include <stdio.h>

char leftTurn(char direction)
{
    char newDirection;
    switch(direction)
    {
	case 'N': newDirection = 'W';
	    break;
	case 'E': newDirection = 'N';
	    break;
	case 'S': newDirection = 'E';
	    break;
	case 'W': newDirection = 'S';
	    break;
    }

	return newDirection;
}
