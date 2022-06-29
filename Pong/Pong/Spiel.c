#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Spiel.h"

struct Spiel* spiel_erzeugen()
{
	srand(time(NULL));
	struct Spiel* spiel = (struct Spiel*)malloc(sizeof(struct Spiel));

	if (spiel == NULL)
	{
		return NULL;
	}
	else
	{
		spiel_init(spiel);
		return spiel;
	}
}
void spiel_init(struct Spiel* spiel_ptr)
{
	punktestand_init(&spiel_ptr->punktestand);
	spieler_init(&spiel_ptr->spieler1,1);
	spieler_init(&spiel_ptr->spieler2,2);
	spielfeld_init(&spiel_ptr->spielfeld);
	ball_init(&spiel_ptr->ball);
	eingabe_init(&spiel_ptr->eingabe);
}
void spiel_zeichnen(struct Spiel* spiel_ptr)
{
	spielfeld_zeichnen(&spiel_ptr->spielfeld);
	ball_zeichnen(&spiel_ptr->ball);
	spieler_zeichen(&spiel_ptr->spieler1);
	spieler_zeichen(&spiel_ptr->spieler2);
	punktestand_zeichnen(&spiel_ptr->punktestand);

}
char spiel_spieler_bewegung_erlaubt(const struct Spieler* spieler_ptr, char bewegung)
{
	if (bewegung == SPIELER_1_HOCH || bewegung == SPIELER_2_HOCH)
	{
		if (rechteck_oberseite(spieler_ptr) <= SPIELFELD_OFFSET_Y + 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (bewegung == SPIELER_1_RUNTER || bewegung == SPIELER_2_RUNTER)
	{
		if (rechteck_unterseite(spieler_ptr) >= SPIELFELD_OFFSET_Y + SPIELFELD_YSIZE - 1 )
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
} 
void spiel_update_spieler(struct Spiel* spiel_ptr)
{
	if (spiel_spieler_bewegung_erlaubt(&spiel_ptr->spieler1,spiel_ptr->eingabe.letzte_eingabe_spieler_1))
	{
		if (spiel_ptr->eingabe.letzte_eingabe_spieler_1 == SPIELER_1_HOCH)
		{
			spieler_hoch(&spiel_ptr->spieler1);
			
		}
		else if (spiel_ptr->eingabe.letzte_eingabe_spieler_1 == SPIELER_1_RUNTER)
		{
			spieler_runter(&spiel_ptr->spieler1);

		}
		spiel_ptr->eingabe.letzte_eingabe_spieler_1 = 'X';
	}
	if (spiel_spieler_bewegung_erlaubt(&(spiel_ptr->spieler2), spiel_ptr->eingabe.letzte_eingabe_spieler_2))
	{
		if (spiel_ptr->eingabe.letzte_eingabe_spieler_2 == SPIELER_2_HOCH)
		{
			spieler_hoch(&spiel_ptr->spieler2);
		}
		else if (spiel_ptr->eingabe.letzte_eingabe_spieler_2 == SPIELER_2_RUNTER)
		{
			spieler_runter(&spiel_ptr->spieler2);
		}
		spiel_ptr->eingabe.letzte_eingabe_spieler_2 = 'X';
	}
}
void spiel_torlinientechnik(struct Spiel* spiel_ptr)
{
	if (ball_rechteseite(&spiel_ptr->ball) >= (SPIELFELD_OFFSET_X + SPIELFELD_XSIZE - 2))
	{
		spiel_ptr->punktestand.punkte_spieler1++;
		punktestand_zeichnen(&spiel_ptr->punktestand);
		ball_einwurf(&spiel_ptr->ball);
	}
	else if (ball_linkeseite(&spiel_ptr->ball) <= (SPIELFELD_OFFSET_X + 2))
	{
		spiel_ptr->punktestand.punkte_spieler2++;
		punktestand_zeichnen(&spiel_ptr->punktestand);
		ball_einwurf(&spiel_ptr->ball);
	}
}
void spiel_update_ball(struct Spiel* spiel_ptr)
{

	if (ball_oberseite(&spiel_ptr->ball) <= SPIELFELD_OFFSET_Y + 1 || ball_unterseite(&spiel_ptr->ball) >= SPIELFELD_YSIZE + SPIELFELD_OFFSET_Y - 1)
	{
		spiel_ptr->ball.y_geschwindigkeit *= -1;
	}
	
	if (ball_linkeseite(&spiel_ptr->ball) <= spieler_rechteseite(&spiel_ptr->spieler1)
		&& ball_oberseite(&spiel_ptr->ball) >= spieler_oberseite(&spiel_ptr->spieler1)
		&& ball_unterseite(&spiel_ptr->ball) <= spieler_unterseite(&spiel_ptr->spieler1))
	{
		spiel_ptr->ball.x_geschwindigkeit *= -1;
	}

	if (ball_rechteseite(&spiel_ptr->ball) >= spieler_linkeseite(&spiel_ptr->spieler2)
		&& ball_oberseite(&spiel_ptr->ball) >= spieler_oberseite(&spiel_ptr->spieler2)
		&& ball_oberseite(&spiel_ptr->ball) <= spieler_unterseite(&spiel_ptr->spieler2))
	{
		spiel_ptr->ball.x_geschwindigkeit *= -1;
	}
	spiel_torlinientechnik(spiel_ptr);
	ball_update(&spiel_ptr->ball);
}
void run(struct Spiel* spiel_ptr)
{
	spiel_zeichnen(spiel_ptr);
	while (spiel_ptr->punktestand.punkte_spieler1 < 3 &&
		spiel_ptr->punktestand.punkte_spieler2 < 3)
	{
		eingabe_einlesen(&(spiel_ptr->eingabe));
		spiel_update_spieler(spiel_ptr);
		spielfeld_zeichne_mittellinie(&(spiel_ptr->spielfeld));
		spiel_update_ball(spiel_ptr);
		punktestand_zeichnen(&(spiel_ptr->punktestand));
		Sleep(5);
	}
}