#ifdef _WIN32
#include <Windows.h> //Sleep
#include <conio.h> //Nicht-blockierendes Einlesen
#else
#include <unistd.h> //sleep
#endif
#include <stdlib.h>
#include <stdio.h>
struct Eingabe
{
	char letzte_eingabe_spieler_1;
	char letzte_eingabe_spieler_2;
};
void eingabe_init(struct Eingabe* eingabe_ptr);
void eingabe_einlesen(struct Eingabe* eingabe_ptr);
