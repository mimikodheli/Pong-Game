#include <stdio.h>
#include <stdlib.h>

#include "Spieler.h"

void spieler_init(struct Spieler* spieler_ptr, int nummer)
{
	if (nummer == 1)
	{
		spieler_ptr->spieler_nummer = SPIELER_1;
		spieler_ptr->rechteck.hoehe = SPIELER_HOEHE;
		spieler_ptr->rechteck.breite = SPIELER_BREITE;
		spieler_ptr->rechteck.symbol = SPIELER_SYMBOL;
		spieler_ptr->rechteck.position.p_x = SPIELER_1_XPOS;
		spieler_ptr->rechteck.position.p_y = SPIELER_YPOS;
	}
	else if(nummer == 2)
	{
		spieler_ptr->spieler_nummer = SPIELER_2;
		spieler_ptr->rechteck.hoehe = SPIELER_HOEHE;
		spieler_ptr->rechteck.breite = SPIELER_BREITE;
		spieler_ptr->rechteck.symbol = SPIELER_SYMBOL;
		spieler_ptr->rechteck.position.p_x = SPIELER_2_XPOS;
		spieler_ptr->rechteck.position.p_y = SPIELER_YPOS;
	}
}
struct Spieler* spieler_erzeugen(int nummer)
{
	struct Spieler* spieler = (struct Spieler*)malloc(sizeof(struct Spieler));

	if (nummer == 1)
	{
		if (spieler == NULL)
		{
			return NULL;
		}
		else
		{
			spieler_init(spieler, nummer);
			return spieler;
		}
	}
	else if (nummer == 2)
	{
		if (spieler == NULL)
		{
			return NULL;
		}
		else
		{
			spieler_init(spieler, nummer);
			return spieler;
		}
	}
}

void spieler_hoch(struct Spieler* spieler_ptr)
{
	rechteck_hoch(&spieler_ptr->rechteck);
}
void spieler_runter(struct Spieler* spieler_ptr)
{
	rechteck_runter(&spieler_ptr->rechteck);
}
void spieler_rechts(struct Spieler* spieler_ptr)
{
	rechteck_rechts(&spieler_ptr->rechteck);
}
void spieler_links(struct Spieler* spieler_ptr)
{
	rechteck_links(&spieler_ptr->rechteck);
}
int spieler_linkeseite(struct Spieler* spieler_ptr)
{	
	return 	rechteck_linkeseite(&spieler_ptr->rechteck); //spieler_linkeseite = spieler_ptr->rechteck.position.p_x;
}
int spieler_rechteseite(struct Spieler* spieler_ptr)
{
	return 	rechteck_rechteseite(&spieler_ptr->rechteck);
}
int spieler_oberseite(struct Spieler* spieler_ptr)
{
	return 	rechteck_oberseite(&spieler_ptr->rechteck);
}
int spieler_unterseite(struct Spieler* spieler_ptr)
{
	return rechteck_unterseite(&spieler_ptr->rechteck);
}
void spieler_zeichen(const struct Spieler* spieler_ptr)
{
	rechteck_zeichnen(&spieler_ptr->rechteck);
}
void spieler_loeschen(struct Spieler* spieler_ptr)
{
	rechteck_loeschen(&spieler_ptr->rechteck);

}


