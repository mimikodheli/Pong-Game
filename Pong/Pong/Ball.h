#ifndef BALL
#define BALL


#include "Configuration.h"
#include "Position.h"
#include "Console.h"
#include "Rechteck.h"


struct Ball 
{
	struct Rechteck rechteck;
	float x_geschwindigkeit;
	float y_geschwindigkeit;
};

struct Ball* ball_erzeugen();
void ball_init(struct Ball* ball_ptr);
void ball_einwurf(struct Ball* ball_ptr);
void ball_zeichnen(struct Ball* ball_ptr);
void ball_loeschen(struct Ball* ball_ptr);
int ball_rechteseite(struct Ball* ball_ptr);
int ball_linkeseite(struct Ball* ball_ptr);
int ball_oberseite(struct Ball* ball_ptr);
int ball_unterseite(struct Ball* ball_ptr);

struct Ball* ball_nextPosition(struct Ball* ball_ptr);
void ball_update(struct Ball* ball_ptr);
#endif  