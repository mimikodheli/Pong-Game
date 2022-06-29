#include "Configuration.h"
#include "Eingabe.h"

void eingabe_init(struct Eingabe* eingabe_ptr)
{
	eingabe_ptr->letzte_eingabe_spieler_1 = 'X';
	eingabe_ptr->letzte_eingabe_spieler_2 = 'X';
}
void eingabe_einlesen(struct Eingabe* eingabe_ptr)
{
	char c = 'X';
	for (int i = 0; i < 1; i++)
	{
		if (_kbhit()) c = _getch();
		if (c == SPIELER_1_HOCH || c == SPIELER_1_LINKS ||
			c == SPIELER_1_RUNTER || c == SPIELER_1_RECHTS)
			eingabe_ptr->letzte_eingabe_spieler_1 = c;
		if (c == SPIELER_2_HOCH || c == SPIELER_2_LINKS ||
			c == SPIELER_2_RUNTER || c == SPIELER_2_RECHTS)
			eingabe_ptr->letzte_eingabe_spieler_2 = c;
		Sleep(100);
	}
}