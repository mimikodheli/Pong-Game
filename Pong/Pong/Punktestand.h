#pragma once
#include "Configuration.h"
#include "Position.h"
#include "Console.h"
#include "Rechteck.h"
#include <stdlib.h>
#include <stdio.h>

struct Punktestand
{
	struct Position position;
	int punkte_spieler1;
	int punkte_spieler2;
};


void punktestand_init(struct Punktestand* punktestand_ptr);
void digit_ausgabe(int nummer);
void punktestand_zeichnen(struct Punktestand* p_ptr);

