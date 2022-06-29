#pragma once
#include "Configuration.h"
#include "Position.h"
#include "Console.h"
#include "Rechteck.h"
#include "Ball.h"
#include "Position.h"
#include "Punktestand.h"
#include "Rechteck.h"
#include "Spieler.h"
#include "Spielfeld.h"
#include "Eingabe.h"
#include "Ball.h"

#include <stdlib.h>
#include <stdio.h>

struct Spiel
{
	struct Spieler spieler1;
	struct Spieler spieler2;
	struct Punktestand punktestand;
	struct Spielfeld spielfeld;
	struct Ball ball;
	struct Eingabe eingabe;

};

struct Spiel* spiel_erzeugen();
void spiel_init(struct Spiel* spiel_ptr);
void spiel_zeichnen(struct Spiel* spiel_ptr);
char spiel_spieler_bewegung_erlaubt(const struct Spieler* spieler_ptr, char bewegung);
void spiel_update_spieler(struct Spiel* spiel_ptr);
void spiel_torlinientechnik(struct Spiel* spiel_ptr);
void spiel_update_ball(struct Spiel* spiel_ptr);
void run(struct Spiel* spiel_ptr);