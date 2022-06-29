#ifndef RECHTECK
#define RECHTECK


#include "Configuration.h"
#include "Position.h"
#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
struct Rechteck
{
	struct Position position;
	int breite;
	int hoehe;
	char symbol;
};

struct Rechteck* rechteck_erzeugen(float x, float y, int breite, int hoehe, char symbol);
//Zeichnet das Rechteck auf der Konsole
void rechteck_zeichnen(const struct Rechteck* rechteck_ptr);
void rechteck_loeschen(const struct Rechteck* rechteck_ptr);
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_hoch(struct Rechteck* rechteck_ptr);
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_runter(struct Rechteck* rechteck_ptr);
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_rechts(struct Rechteck* rechteck_ptr);
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_links(struct Rechteck* rechteck_ptr);
//Gibt die x-Koordinate der rechten Seite des Rechtecks zurück
int rechteck_rechteseite(struct Rechteck* rechteck_ptr);
//Gibt die x-Koordinate der linken Seite des Rechtecks zurück
int rechteck_linkeseite(struct Rechteck* rechteck_ptr);
//Gibt die y-Koordinate der oberen Seite des Rechtecks zurück
int rechteck_oberseite(struct Rechteck* rechteck_ptr);
//Gibt die y-Koordinate der unteren Seite des Rechtecks zurück
int rechteck_unterseite(struct Rechteck* rechteck_ptr);

#endif  