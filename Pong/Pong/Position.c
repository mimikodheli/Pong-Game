#include <stdio.h>
#include <stdlib.h>

#include "Position.h"



void position_setze_X(struct Position* p, float x)
{
	p->p_x = x;
}

void position_setze_Y(struct Position* p, float y)
{
	p->p_y = y;
}
