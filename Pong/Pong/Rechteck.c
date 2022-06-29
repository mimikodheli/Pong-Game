#include <stdio.h>
#include <stdlib.h>

#include "Rechteck.h"

//Erzeugt ein Rechteck auf dem Heap mit den übergebenen Werten und gibt den Zeiger zurück
struct Rechteck* rechteck_erzeugen(float x, float y, int breite, int hoehe, char symbol)
{
	struct Rechteck* rechteck = (struct Rechteck*)malloc(sizeof(struct Rechteck));

	if (rechteck == NULL)
	{
		return NULL;
	}
	else
	{
		rechteck->breite = breite;
		rechteck->hoehe = hoehe;
		rechteck->symbol = symbol;
		rechteck->position.p_x = x;
		rechteck->position.p_y = y;
	}
	return rechteck;


}
//Zeichnet das Rechteck auf der Konsole
void rechteck_zeichnen(const struct Rechteck* rechteck_ptr)
{
	for (int y = (int)(rechteck_ptr->position.p_y); y < (int)(rechteck_ptr->hoehe + rechteck_ptr->position.p_y); y++)
	{
		for (int x = (int)(rechteck_ptr->position.p_x); x < (int)(rechteck_ptr->breite + rechteck_ptr->position.p_x); x++)
		{
			cursor_zeichne_punkt(x, y, rechteck_ptr->symbol);
			
		}
	}
}
void rechteck_loeschen(const struct Rechteck* rechteck_ptr)
{
	for (int y = (int)(rechteck_ptr->position.p_y); y < (int)(rechteck_ptr->hoehe + rechteck_ptr->position.p_y); y++)
	{
		for (int x = (int)(rechteck_ptr->position.p_x); x < (int)(rechteck_ptr->breite + rechteck_ptr->position.p_x); x++)
		{
			cursor_zeichne_punkt(x, y, ' ');
		}
	}
}
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_hoch(struct Rechteck* rechteck_ptr)
{
	rechteck_loeschen(rechteck_ptr);
	rechteck_ptr->position.p_y -= 1;
	rechteck_zeichnen(rechteck_ptr);

}
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_runter(struct Rechteck* rechteck_ptr)
{
	rechteck_loeschen(rechteck_ptr);
	rechteck_ptr->position.p_y += 1;
	rechteck_zeichnen(rechteck_ptr);
}
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_rechts(struct Rechteck* rechteck_ptr)
{
	rechteck_loeschen(rechteck_ptr);
	rechteck_ptr->position.p_x += 1;
	rechteck_zeichnen(rechteck_ptr);
}
//Löscht das Rechteck->ändert Position->Zeichnet neu
void rechteck_links(struct Rechteck* rechteck_ptr)
{
	rechteck_loeschen(rechteck_ptr);
	rechteck_ptr->position.p_y -= 1;
	rechteck_zeichnen(rechteck_ptr);
}
//Gibt die x-Koordinate der rechten Seite des Rechtecks zurück
int rechteck_rechteseite(struct Rechteck* rechteck_ptr)
{
	
	return 	 (int)rechteck_ptr->position.p_x + rechteck_ptr->breite;
}
//Gibt die x-Koordinate der linken Seite des Rechtecks zurück
int rechteck_linkeseite(struct Rechteck* rechteck_ptr)
{
	
	return 	(int)rechteck_ptr->position.p_x;

}
//Gibt die y-Koordinate der oberen Seite des Rechtecks zurück
int rechteck_oberseite(struct Rechteck* rechteck_ptr)
{
	
	return (int)rechteck_ptr->position.p_y;
}
//Gibt die y-Koordinate der unteren Seite des Rechtecks zurück
int rechteck_unterseite(struct Rechteck* rechteck_ptr)
{
	
	return (int)rechteck_ptr->position.p_y + rechteck_ptr->hoehe;
}