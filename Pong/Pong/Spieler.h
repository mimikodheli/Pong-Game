#ifndef SPIELER
#define SPIELER


#include "Configuration.h"
#include "Position.h"
#include "Console.h"
#include "Rechteck.h"
#include <stdlib.h>
#include <stdio.h>

struct Spieler
{
	struct Rechteck rechteck;
	int spieler_nummer;
};
void spieler_init(struct Spieler* spieler_ptr, int nummer);
struct Spieler* spieler_erzeugen(int nummer);

void spieler_hoch(struct Spieler* spieler_ptr);
void spieler_runter(struct Spieler* spieler_ptr);
void spieler_rechts(struct Spieler* spieler_ptr);
void spieler_links(struct Spieler* spieler_ptr);
int spieler_linkeseite(struct Spieler* spieler_ptr);
int spieler_rechteseite(struct Spieler* spieler_ptr);
int spieler_oberseite(struct Spieler* spieler_ptr);
int spieler_unterseite(struct Spieler* spieler_ptr);
void spieler_zeichen(struct Spieler* spieler_ptr);
void spieler_loeschen(struct Spieler* spieler_ptr);
#endif 





