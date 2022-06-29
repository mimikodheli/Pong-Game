#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ball.h"

struct Ball* ball_erzeugen()
{
	struct Ball* ball = (struct Ball*)malloc(sizeof(struct Ball));
	if (ball == NULL)
	{
		return NULL;
	}
	else
	{
		ball_init(ball);
		return ball;
	}
}
void ball_init(struct Ball* ball_ptr)
{
	ball_ptr->rechteck.breite = BALL_BREITE;
	ball_ptr->rechteck.hoehe = BALL_HOEHE;
	ball_ptr->rechteck.symbol = BALL_SYMBOL;
	ball_ptr->rechteck.position.p_x = BALL_XPOS_START;
	ball_ptr->rechteck.position.p_y = BALL_YPOS_START;
	ball_ptr->x_geschwindigkeit = 0.0;
	ball_ptr->y_geschwindigkeit = 0.0;
	ball_einwurf(ball_ptr);
}
void ball_einwurf(struct Ball* ball_ptr)
{
	ball_loeschen(ball_ptr);
	ball_ptr->x_geschwindigkeit = ((rand() % 8) + 3) / 10.0;
	ball_ptr->y_geschwindigkeit = ((rand() % 8) + 3) / 10.0;
	ball_ptr->rechteck.position.p_x = BALL_XPOS_START;
	ball_ptr->rechteck.position.p_y = BALL_YPOS_START;
	ball_zeichnen(ball_ptr);
}
void ball_zeichnen(struct Ball* ball_ptr)
{
	rechteck_zeichnen(&ball_ptr->rechteck);
}
void ball_loeschen(struct Ball* ball_ptr)
{
	rechteck_loeschen(&ball_ptr->rechteck);
}
int ball_rechteseite(struct Ball* ball_ptr)
{
	return rechteck_rechteseite(&ball_ptr->rechteck);
}
int ball_linkeseite(struct Ball* ball_ptr)
{
	return rechteck_linkeseite(&ball_ptr->rechteck);
}
int ball_oberseite(struct Ball* ball_ptr)
{
	return rechteck_oberseite(&ball_ptr->rechteck);
}
int ball_unterseite(struct Ball* ball_ptr)
{
	return rechteck_unterseite(&ball_ptr->rechteck);
}
struct Ball* ball_nextPosition(struct Ball* ball_ptr)
{
	struct Ball* neu_ball = (struct Ball*)malloc(sizeof(struct Ball));
	
	memcpy(neu_ball, ball_ptr, sizeof(struct Ball));

	ball_update(neu_ball);
	
	
	return neu_ball;

}
void ball_update(struct Ball* ball_ptr)
{
	ball_loeschen(ball_ptr);
	ball_ptr->rechteck.position.p_x = ball_ptr->rechteck.position.p_x + ball_ptr->x_geschwindigkeit;
	ball_ptr->rechteck.position.p_y = ball_ptr->rechteck.position.p_y + ball_ptr->y_geschwindigkeit;
	ball_zeichnen(ball_ptr);
}